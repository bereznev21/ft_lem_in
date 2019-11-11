def get_lines(f_name):
    with open(f_name, 'rt') as f:
        data = (l.strip() for l in f.read().split('\n'))
    return [l for l in data if l]
