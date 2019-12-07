def maxProduct(nums):
    if not nums:
        return 0
    max_mult = nums[0]
    result = nums[0]
    for i in range(1, len(nums)):
        result *= nums[i]
        if result == 0:
            result = 1
            max_mult = max(0, max_mult)
        max_mult = max(result, max_mult)
    return max_mult


if __name__ == "__main__":
    nums = [-2, 0, -1]
    a = maxProduct(nums)
    print(a)
