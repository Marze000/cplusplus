def productExceptSelf(nums):
    n = len(nums)
    res = [1]*n
    for i in range(n-1):
        res[i+1] = res[i] * nums[i]
    right = 1
    for i in range(n-1, -1, -1):
        res[i] *= right
        right *= nums[i]
    return res


def maxSlidingWindow(nums, k):
    n = len(nums)
    if n < 2 or k == 1:
        return nums
    res = []
    index = [0]
    queue = [nums[0]]
    for i in range(1, n):
        if index[0] <= i-k:
            index.pop(0)
        while index and nums[index[-1]] < nums[i]:
            index.pop()
        index.append(i)
        if i >= k-1:
            res.append(nums[index[0]])
    return res


if __name__ == "__main__":
