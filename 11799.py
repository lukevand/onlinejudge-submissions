import sys
for i, el in enumerate([max([int(x) for x in line.split()]) for line in sys.stdin.readlines()[1:]]):
    print("Case {}: {}".format(i+1, el))
