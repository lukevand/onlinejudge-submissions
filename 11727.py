import sys
for i,e in enumerate([sorted([int(x) for x in line.split()])[1] for line in sys.stdin.readlines()[1:]],1): print("Case %d: %d"%(i,e))
