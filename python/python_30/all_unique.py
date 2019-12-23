def moveZeroes(nums):
    j = 0
    for i in range(len(nums)):
        if nums[i] != 0:
            nums[j] = nums[i]
            j += 1
    while j < len(nums):
        nums[j] = 0
        j += 1
    return nums


if __name__ == "__main__":
    nums = [0, 0, 1]
    a = moveZeroes(nums)
    print(a)
