from scipy.sparse.csgraph import bellman_ford

from .mprint import mprint
from .read import *
from .suurballe import suurballe


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


if __name__ == '__main__':
    main()
    # aj = np.array([
    #     [0, -1, 3, 0],
    #     [0, 0, -1, 3],
    #     [3, 0, 0, -1],
    #     [0, 3, 0, 0],
    # ])
    # dist, pred = bellman_ford(aj,
    #                           return_predecessors=True,
    #                           indices=3)
    # print(pred)
