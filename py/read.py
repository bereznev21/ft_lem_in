from .consts import *


def read_lem_in(f_name):
    def room_idx(room_name):
        for i, r in enumerate(rooms):
            if r == room_name:
                return i

    with open(f_name, 'rt') as f:
        data = [l.strip() for l in f.read().split('\n')]
    data = [l for l in data if l]
    while data[0].startswith("#"):
        data = data[1:]  # skip ant count
    data = data[1:]  # skip ant count
    last_room_idx = 0
    for last_room_idx, l in enumerate(data):
        if len(l.split('-')) == 2:
            break
    rooms = []
    start = end = 0
    for l in data[:last_room_idx]:
        if l.startswith("##start"):
            start = len(rooms)
        if l.startswith("##end"):
            end = len(rooms)
        if l.startswith("#"):
            continue
        rooms.append(l.split()[0])
    aj = np.ones([len(rooms), len(rooms)])
    aj *= DISJ
    for l in data[last_room_idx:]:
        a, b = l.split('-')
        i = room_idx(a)
        j = room_idx(b)
        aj[i, j] = ONE
        aj[j, i] = ONE
    return aj, start, end


def read_matrix(f_name):
    with open(f_name, 'rt') as f:
        data = [l.strip() for l in f.read().split('\n')]
    data = [l for l in data if l]
    start = int(data[0].split()[0])
    end = int(data[0].split()[1])
    data = data[1:]
    n = len(data)
    assert n == len(data[0].split()), "bad matrix"
    aj = np.zeros([n, n])
    for i, line in enumerate(data):
        for j, c in enumerate(line.split()):
            if c == ".":
                aj[i, j] = DISJ
            else:
                aj[i, j] = int(c)
    return aj, start, end
