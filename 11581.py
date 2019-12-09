N = int(input())

dx = [0,0,1,-1]
dy = [1,-1,0,0]

def p(g):
    for a in g:
        print(*a)
    print()

def valid(x, y):
    return 0 <= x < 3 and 0 <= y < 3

def zero(g):
    for i in range(3):
        for j in range(3):
            if g[i][j] != 0:
                return False
    return True

def f(g):
    G = [[0]*3 for _ in range(3)]
    for i in range(3):
        for j in range(3):
            total = 0
            for k in range(4):
                if valid(i + dx[k], j+dy[k]):
                    total += g[i+dx[k]][j+dy[k]]
            G[i][j] = total%2
    return G

for _ in range(N):
    input()
    g = []
    for _ in range(3):
        line = list(map(int, list(input())))
        g.append(line)
    if zero(g):
        print('-1')
        continue
    g = f(g)
    count = 0
    while not zero(g):
        count += 1
        g = f(g)
    print(count)

