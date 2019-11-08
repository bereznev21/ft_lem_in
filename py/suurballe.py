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


def split_node(aj, k):
    aj = np.insert(aj, k, aj[k], axis=0)
    aj = np.insert(aj, k, aj[:, k], axis=1)
    for i in range(aj.shape[0]):
        aj[k, i] = D
        aj[i, k + 1] = D
    aj[k, k + 1] = ZERO
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
        path.insert(i + 1, 0)
        collapser = np.insert(collapser, i, collapser[i], axis=0)  # dup row
        aj = split_node(aj, i)

    return aj, collapser, start, end


def suurballe(aj, start, end):
    all_paths = np.zeros(aj.shape)
    i = 0
    while 1:
        print("reversing path...")
        mprint(aj)
        mprint(all_paths)
        aj2 = suu_reverse_path(aj, all_paths)
        print("done:")
        mprint(aj2)
        aj2, collapser, s, e = split_path_nodes(aj2, all_paths, start, end)
        print("split nodes:")
        mprint(aj2)
        path = bf_shortest_path(aj2, s, e)
        if path is None:
            break
        i += 1
        print("path:")
        mprint(path)
        path = np.matmul(collapser.T, np.matmul(path, collapser))
        all_paths += path
        remove_sym(all_paths)
    return i, all_paths
