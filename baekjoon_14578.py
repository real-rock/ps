def factorial(n):
    x = 1
    for i in range(1, n + 1):
        x = x * i % 1000000007
    return x

def dp(n):
    x_1 = 0
    x_2 = 1
    for i in range(2, n):
        tmp = (x_1 + x_2) * i % 1000000007
        x_1 = x_2
        x_2 = tmp
    return x_2

if __name__ == '__main__':
    n = int(input())
    if n == 1:
        print(0)
    elif n == 2:
        print(2)
    else:
        a = factorial(n)
        b = dp(n)
        print((a * b) % 1000000007)
