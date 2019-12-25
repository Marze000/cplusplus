def lengthOfLIS(self, nums):
    if not nums:
        return 0
    n = len(nums)
    dp = [1]*n
    for i in range(1, n):
        cur_max = 0
        for j in range(i):
            if nums[i] > nums[j]:
                cur_max = max(cur_max, dp[j])
        if cur_max:
            dp[i] = cur_max + 1
    return max(dp)


if __name__ == "__main__":
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    a = lengthOfLIS(nums)
    print(a)
