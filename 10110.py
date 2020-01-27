from math import sqrt
def f(n):
    A = [0 for _ in range(n+1)]
    for i in range(1, n+1):
        j = 1
        while i*j <= n:
            A[i*j] ^= 1
            j += 1
    # print(A[-1])
    return A[-1]

m = 5000
t = [i for i in range(1, m) if f(i) == 1]
s = [i**2 for i in range(1, int(sqrt(m)+1))]
print(t)
print(s)
print(t == s)
