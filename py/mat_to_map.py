from py.map_dump_restore import map_restore, D

if __name__ == '__main__':
    m = map_restore("mat/10.mat")
    with open("maps/generated/10.map", "wt") as f:
        f.write("10\n")
        f.write("##start\n")
        for i in range(m.shape[0] - 1):
            f.write(f"{i} 0 0\n")
        f.write(f"##end\n{m.shape[0] - 1} 0 0\n")
        for i, row in enumerate(m):
            for j in range(i, m.shape[0]):
                c = row[j]
                if c != D:
                    f.write(f"{i}-{j}\n")
