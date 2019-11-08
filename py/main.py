from scipy.sparse.csgraph import bellman_ford
from scipy.sparse.csgraph._tools import csgraph_from_dense

from py.find_path import restore_path2, bf_shortest_path
from py.mprint import mprint
from py.read import *
from py.suurballe import suurballe


def test_bf():
    aj, start, end = read_matrix("mat/300.mat")
    print(aj)
    # indices = np.zeros([aj.shape[0]])
    # indices[0] = 1
    # indices[1] = 1
    # print(indices)
    dist, predecessors = bellman_ford(aj,
                                      return_predecessors=True,
                                      indices=start)
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
    aj, start, end = read_lem_in("maps/qqq_ordered")
    mprint(aj)
    print(start, end)
    # mprint(bf_shortest_path(aj, start, end))
    n, all_paths = suurballe(aj, start, end)
    print("total paths:", n)
    reconstruct_paths(all_paths, start, end)


def draft():
    for aj in (np.array([
        [D, -1, 3, D],
        [D, D, -1, 3],
        [3, D, D, -1],
        [D, 3, D, D],
    ]), np.array([
        [D, 1, D, D],
        [D, D, 1, D],
        [D, D, D, 1],
        [D, D, D, D],
    ])):
        print(bf_shortest_path(aj, 0, aj.shape[0] - 1))


if __name__ == '__main__':
    main()
    # draft()
