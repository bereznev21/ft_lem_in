import sys
from os.path import join, dirname
import webbrowser

VIS_DIR = dirname(__file__)
OUT = join(VIS_DIR, "data.js")
INDEX = join(VIS_DIR, "index.html")

if __name__ == '__main__':
    with open(OUT, 'wt') as f:
        f.write('let data = "\\\n')
        for line in sys.stdin:
            f.write(line.strip())
            f.write("\\n\\\n")
        f.write('";\n')

    webbrowser.open(INDEX)
    print("done, open", INDEX)
