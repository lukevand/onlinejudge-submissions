def bf(D, I):
    A = [0 for _ in range(2**D)]
    x = 1
    # for i in range(I):
    #     x = 1
    while x < 2**D:
        print(x)
        if (I % 2 == 0):
            x = 2*x
            I /= 2
        else:
            x = 2*x + 1
            I = (I + 1)//2
    return x

print(bf(8, 128))
