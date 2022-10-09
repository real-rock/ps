if __name__ == '__main__':
    i = input()
    nums = [int(x) for x in i]
    dp = [0] * (len(nums) + 1)
    if nums[0] == 0:
        print(0)
    else:
        dp[0], dp[1] = 1, 1
        for i in range(2, len(dp)):
            if nums[i - 1] > 0:
                dp[i] += dp[i - 1]
            if 10 <= nums[i - 2] * 10 + nums[i - 1] <= 26:
                dp[i] += dp[i - 2]
        print(dp[-1] % 1000000)
