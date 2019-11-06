import numpy as np
from scipy.sparse.csgraph import bellman_ford, shortest_path
from scipy.sparse.csgraph._shortest_path import NegativeCycleError
from scipy.sparse.csgraph._tools import csgraph_from_dense

from .consts import *


def bf_shortest_path(aj, start, end):
    ajs = csgraph_from_dense(aj, null_value=DISJ)
    try:
        dist, pred = shortest_path(ajs,
                                   method="D",
                                   return_predecessors=True,
                                   indices=end)
    except NegativeCycleError:
        return None
    path = np.zeros(aj.shape)
    k = start
    while k != end:
        if pred[k] == NO_PATH:
            return None
        path[k, pred[k]] = 1
        k = pred[k]
    return path
