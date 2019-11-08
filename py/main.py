from scipy.sparse.csgraph import bellman_ford

from py.find_path import bf_shortest_path
from py.map_dump_restore import map_dump, map_restore
from py.map_generator import generate_map
from py.mprint import mprint
from py.read import *
from py.suurballe import suurballe, suurballe_generator


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


def main():
    aj, start, end = read_lem_in("maps/generated/big1.map")
    # mprint(aj)
    print(start, end)
    # mprint(bf_shortest_path(aj, start, end))
    for i, all_paths in enumerate(suurballe_generator(aj, start, end)):
        print("total paths:", i + 1)
        reconstruct_paths(all_paths, start, end)


def test_generated_maps():
    start = 0
    end = 4
    aj = generate_map(end + 1, end // 2, 3)
    # dump_map(aj)
    print(aj)
    n, all_paths = suurballe(aj, start, end)
    try:
        reconstruct_paths(all_paths, start, end)
    except AssertionError:
        map_dump(aj)
        raise


def debug_suurballe():
    aj = map_restore("mat/bad_suurballe_5.mat")
    start = 0
    end = aj.shape[0] - 1
    n, all_paths = suurballe(aj, start, end)
    print(n)
    mprint(all_paths)


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
    # main()
    # test_generated_maps()
    debug_suurballe()
    # draft()
