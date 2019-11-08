import numpy as np
from scipy.sparse.csgraph import bellman_ford, shortest_path
from scipy.sparse.csgraph._shortest_path import NegativeCycleError
from scipy.sparse.csgraph._tools import csgraph_from_dense

from py.consts import *


def restore_path1(aj, pred, start, end):
    path = np.zeros(aj.shape)
    k = start
    while k != end:
        if pred[k] == NO_PATH:
            return None
        path[k, pred[k]] = 1
        k = pred[k]
    return path


def restore_path2(aj, pred, start, end):
    path = np.zeros(aj.shape)
    k = end
    while k != start:
        if pred[k] == NO_PATH:
            return None
        path[pred[k], k] = 1
        k = pred[k]
    return path


def bf_shortest_path(aj, start, end):
    try:
        dist, pred = shortest_path(csgraph_from_dense(aj, null_value=D),
                                   method="BF",
                                   return_predecessors=True,
                                   indices=start)
    except NegativeCycleError:
        return None
    return restore_path2(aj, pred, start, end)
