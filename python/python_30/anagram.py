def lengthOfLIS(nums):
    max_cout = 0
    for i in range(len(nums)):
        cout = 0
        temp = nums[i]
        for j in range(i+1, len(nums)):
            if nums[j] > temp:
                temp = nums[j]
                cout += 1
        max_cout = max(max_cout, cout)
    return max_cout


if __name__ == "__main__":
    nums = [10, 9, 2, 5, 3, 7, 101, 18]
    a = lengthOfLIS(nums)
    print(a)
