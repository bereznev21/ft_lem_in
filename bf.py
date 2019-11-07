import numpy as np
from scipy.sparse.csgraph import bellman_ford
from scipy.sparse.csgraph._shortest_path import NegativeCycleError

NO_PATH = -9999
DISJ = 999999


def read_data(f_name):
    with open(f_name, 'rt') as f:
        data = [l.strip() for l in f.read().split('\n')]
    data = [l for l in data if l]
    start = int(data[0].split()[0])
    end = int(data[0].split()[1])
    data = data[1:]
    n = len(data)
    assert n == len(data[0].split()), "bad matrix"
    aj = np.zeros([n, n], dtype=np.int32)
    for i, line in enumerate(data):
        for j, c in enumerate(line.split()):
            if c == ".":
                aj[i, j] = DISJ
            else:
                aj[i, j] = int(c)
    return aj, start, end


def suu_reverse_path(aj, all_paths):
    ret = aj[:]
    for i, row in enumerate(all_paths):
        for j, p in enumerate(row):
            if (p):
                ret[j, i] = -aj[i, j]
                ret[i, j] = DISJ
    return ret


def remove_sym(m):
    for i, row in enumerate(m):
        for j, p in enumerate(row):
            if m[i, j] and m[j, i]:
                m[i, j] = 0
                m[j, i] = 0


def split_node(aj, k):
    aj = np.insert(aj, k, aj[k], axis=0)
    aj = np.insert(aj, k, aj[:, k], axis=1)
    for i in range(aj.shape[0]):
        aj[k, i] = DISJ
        aj[i, k + 1] = DISJ
    aj[k, k + 1] = 0
    return aj


def split_path_nodes(aj, path, start, end):
    collapser = np.identity(aj.shape[0])
    path = [sum(row) for row in path]
    for i in range(0, aj.shape[0]):
        if i == start or i == end:
            continue
        if not path[i]:
            continue
        if start > i:
            start += 1
        if end > i:
            end += 1
        path.insert(i, 1)
        collapser = np.insert(collapser, i, collapser[i], axis=0)  # dup row
        aj = split_node(aj, i)

    return aj, collapser, start, end


def bf_shortest_path(aj, start, end):
    try:
        dist, pred = bellman_ford(aj, return_predecessors=True, indices=start)
    except NegativeCycleError:
        return None
    path = np.zeros(aj.shape)
    k = end
    while k != start:
        if pred[k] == NO_PATH:
            return None
        path[pred[k], k] = 1
        k = pred[k]
    return path


def suurballe(aj, start, end):
    all_paths = np.zeros(aj.shape)
    i = 0
    while 1:
        aj2 = suu_reverse_path(aj, all_paths)
        aj2, collapser, s, e = split_path_nodes(aj2, all_paths, start, end)
        path = bf_shortest_path(aj2, s, e)
        if path is None:
            break
        i += 1
        path = np.matmul(collapser.T, np.matmul(path, collapser))
        all_paths += path
        remove_sym(all_paths)
    return i, all_paths


def test_bf():
    aj, start, end = read_data("mat/300.mat")
    print(aj)
    # indices = np.zeros([aj.shape[0]])
    # indices[0] = 1
    # indices[1] = 1
    # print(indices)
    dist, predecessors = bellman_ford(aj, return_predecessors=True, indices=start)
    print(dist)
    print(predecessors)
    k = end
    while k != start:
        print(k, "<-", end="")
        if k == NO_PATH:
            print("NO PATH")
            break
        k = predecessors[k]
    print(k)


def reconstruct_paths(all_paths, start, end):
    used_nodes = set()
    for i, x in enumerate(all_paths[start]):
        if not x:
            continue
        print(f"{start}->", end="")
        while i != end:
            print(f"{i}->", end="")
            assert i not in used_nodes, "node collision"
            used_nodes.add(i)
            for j, y in enumerate(all_paths[i]):
                if y:
                    i = j
                    break
        print(i)
    print(used_nodes)


def main():
    aj, start, end = read_data("mat/300.mat")
    # print(bf_shortest_path(aj, start, end))
    n, all_paths = suurballe(aj, start, end)
    reconstruct_paths(all_paths, start, end)


if __name__ == '__main__':
    main()
