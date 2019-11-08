from py.consts import *
from py.utils import get_lines


def map_dump(aj):
    with open("map_dump.mat", 'wt') as f:
        m, n = aj.shape
        f.write(f"{m} {n}\n")
        for row in aj:
            for c in row:
                if c == D:
                    f.write('.')
                else:
                    f.write(str(int(c)))
            f.write("\n")


def map_restore(f_name):
    data = get_lines(f_name)
    m, n = data[0].split()
    assert m == n
    m = int(m)
    aj = np.zeros([m, m])
    for i, l in enumerate(data[1:]):
        for j, c in enumerate(l):
            if c == '.':
                aj[i][j] = D
            else:
                aj[i][j] = int(c)

    return aj
