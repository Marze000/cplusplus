def minSubArrayLen(s, nums):
    if not sum or s>sum(nums):
        return 0
    left ,right,end = 0,1,len(nums)+1
    min_num  = len(nums)
    while right<end:
        if sum(nums[left:right])>=s:
            min_num = min(min_num,len(nums[left:right]))
            left+=1
        else:
            right+=1
    return min_num

if __name__ == "__main__":
    s = 7
    nums = [2,3,1,2,4,3]
    a = minSubArrayLen(s, nums)
    print(a)