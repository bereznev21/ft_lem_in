import numpy as np
from py.consts import *
from py.mprint import mprint
from py.find_path import bf_shortest_path


def suu_reverse_path(aj, all_paths):
    ret = np.copy(aj[:])
    for i, row in enumerate(all_paths):
        for j, p in enumerate(row):
            if (p):
                # ret[j, i] = -aj[i, j]
                ret[j, i] = aj[i, j]
                ret[i, j] = D
    return ret


def remove_sym(path):
    for i, row in enumerate(path):
        for j, p in enumerate(row):
            if path[i, j] and path[j, i]:
                path[i, j] = 0
                path[j, i] = 0


def split_path_nodes(aj, path, start, end):
    def split_node(aj, k):
        aj = np.insert(aj, k, aj[k], axis=0)
        aj = np.insert(aj, k, aj[:, k], axis=1)
        for i in range(aj.shape[0]):
            aj[k, i] = D
            aj[i, k + 1] = D
        aj[k, k + 1] = ZERO
        return aj

    collapser = np.identity(aj.shape[0])
    path = list(sum(path))
    for i in range(0, aj.shape[0]):
        if i == start or i == end:
            continue
        if not path[i]:
            continue
        if start > i:
            start += 1
        if end > i:
            end += 1
        path.insert(i + 1, 0)
        collapser = np.insert(collapser, i, collapser[i], axis=0)  # dup row
        aj = split_node(aj, i)

    return aj, collapser, start, end


def triplewise(seq):
    it = iter(seq)
    a = next(it)
    b = next(it)
    for c in it:
        yield a, b, c
        a = b
        b = c


def pairwise(seq):
    it = iter(seq)
    a = next(it)
    for b in it:
        yield a, b
        a = b


def iter_path(path, k, end):
    yield k
    while k != end:
        for i in range(path.shape[0]):
            if path[k, i]:
                k = i
                break
        yield k


def separate_paths(path, start, end):
    for i, e in enumerate(path[start]):
        if not e:
            continue
        yield iter_path(path, i, end)


def split_paths_nodes(aj, path, start, end):
    def split_node(aj, k, prev, next):  # insert columns and rows in the end;
        n = aj.shape[0]
        aj = np.insert(aj, n, aj[k], axis=0)
        aj = np.insert(aj, n, aj[:, k], axis=1)
        for i in range(aj.shape[0]):
            if i != prev:
                aj[k, i] = D
            if i != next:
                aj[i, n] = D
        aj[n, k] = ZERO
        return aj

    collapser = np.identity(aj.shape[0])

    for p in separate_paths(path, start, end):
        prev = start
        for k, next in pairwise(p):
            aj = split_node(aj, k, prev, next)
            collapser = np.insert(collapser, collapser.shape[0], collapser[k],
                                  axis=0)  # dup row
            prev = aj.shape[0] - 1  # last newly created node
    return aj, collapser


def suurballe(aj, start, end):
    all_paths = np.zeros(aj.shape)
    i = -1
    for i, all_paths in enumerate(suurballe_generator(aj, start, end)):
        pass
    return i + 1, all_paths


def suurballe_generator(aj, start, end):
    for i in range(aj.shape[0]):
        aj[i, i] = D
    all_paths = np.zeros(aj.shape)
    i = 0
    while 1:
        aj2 = suu_reverse_path(aj, all_paths)
        aj2, collapser = split_paths_nodes(aj2, all_paths, start, end)
        path = bf_shortest_path(aj2, start, end)
        if path is None:
            break
        i += 1
        print(f"path: {i}")
        path = np.matmul(collapser.T, np.matmul(path, collapser))
        all_paths += path
        remove_sym(all_paths)
        yield np.copy(all_paths)
