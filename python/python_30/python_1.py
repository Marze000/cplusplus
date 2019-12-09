def largestNumber(nums):
    nums = [str(x)for x in nums]
    nums = sorted(nums, cmp=lambda x, y: cmp(x+y, y+x), reverse=True)
    return ''.join(nums).lstrip('0') or '0'


if __name__ == "__main__":
    nums = [3, 30, 34, 5, 9]
    a = largestNumber(nums)
    print(a)
