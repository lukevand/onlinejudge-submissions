from sys import stdin

N = int(stdin.readline())

for _ in range(N):
    line = stdin.readline()
    seen = [0 for _ in range(26)]
    vertexLabelList = [0 for _ in range(26)]
    edgeCount = 0
    acorn = 0

    while not line.startswith('*'):
        x, y = line[1], line[3]
        seen[ord(x)-65] = 1
        seen[ord(y)-65] = 1
        edgeCount += 1
        line = stdin.readline()

    vertexLabels = stdin.readline().strip().split(',')
    vertexCount = len(vertexLabels)

    for label in vertexLabels:
        vertexLabelList[ord(label)-65] = 1

    for i, j in zip(seen, vertexLabelList):
        if i ^ j == 1:
            acorn += 1

    components = vertexCount - edgeCount
    print("There are {} tree(s) and {} acorn(s).".format(components-acorn, acorn))

