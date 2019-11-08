import numpy as np
from random import randrange

from py.consts import D


def generate_map(size, path_len, n_paths):
    aj = np.ones([size, size]) * D

    for _ in range(n_paths):
        k = 0
        visited = set()
        for i in range(path_len):
            while 1:
                k2 = randrange(1, size - 1)
                if k2 not in visited:
                    break
                visited.add(k2)
            aj[k, k2] = 1
            aj[k2, k] = 1
            k = k2
        aj[k, size - 1] = 1
        aj[size - 1, k] = 1
    return aj
