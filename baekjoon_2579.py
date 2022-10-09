if __name__ == '__main__':
    n = int(input())
    l = [0] * (n + 1)
    dp = [0] * (n + 1)
    for i in range(1, n + 1):
        l[i] = int(input())
    if n < 1:
        print(l[0])
    elif n < 2:
        print(l[1])
    elif n < 3:
        print(l[1] + l[2])
    else:
        dp[1] = l[1]
        dp[2] = l[1] + l[2]
        for i in range(3, n + 1):
            dp[i] = max(dp[i - 3] + l[i - 1], dp[i - 2]) + l[i]
        print(dp[-1])
