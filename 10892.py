from sympy import lcm

def f(n):
    return list(set([(min(x, y), max(x,y)) for x in range(1, n+1) for y in range(1, i+1) if lcm(x, y) == n]))

for i in range(1, 30):
    print(i, len(f(i)))
