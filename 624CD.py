from sys import stdin

line = stdin.readline().split()
N = int(line[0])
songs = [int(x) for x in line[2:]]

sol = set()
def backtrack(t, maximum):
    if len(t) == 0:
        return sol

