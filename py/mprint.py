from .consts import *

def mprint(mat):
    m, n = mat.shape
    print("  |", end="")
    for i in range(n):
        print("{:2d} ".format(i), end="")
    print("")
    print("--+", end="")
    for i in range(n):
        print("---", end="")
    print("")
    for i, row in enumerate(mat):
        print("{:2d}|".format(i), end="")
        for c in row:
            if c == DISJ:
                print(" . ", end="")
            elif c == ZERO:
                print(" o ", end="")
            elif c == ONE:
                print(" # ", end="")
            elif c == -ONE:
                print(" X ", end="")
            else:
                print("{:2d} ".format(int(c)), end="")
        print()
    print()
    sys.stdout.flush()
