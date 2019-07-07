def fib(num):
    a, b = 0, 1
    for i in range(0, num):
        yield a
        a, b = b, a+ b

fibanoci = fib(10)
for i in fibanoci:
    print(i)



