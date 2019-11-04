
'''
# 判断列表中是否有重复的元素
def all_unique(lit):
    #如果没有重复的元素返回 True
    # set 的作用是给列表去重
    return len(lit) == len(set(lit))

x = (1,2,3,4,5,2,5,6)

for i in x:
    if x.count(i) > 1:
        print(i)
        break
'''
'''

def threeSum(nums):
    ret = []
    if not nums:
        return ret
    nums = sorted(nums) 
    for i in range(len(nums)-2):
        left = i+1
        right = len(nums)-1
        # -4 -1 -1 0 1 2
        while left <right:
            temp = nums[i]+nums[left]+nums[right]
            templist = [nums[i],nums[left],nums[right]]
            if temp ==0 and templist not in ret:
               ret.append(templist)
               left+=1
            elif temp > 0:
                right -=1
            else:
                left+=1 
    return ret

def threeSum(nums):
    nums = sorted(nums)
    res = []
    for i in range(len(nums)-2):
        left = i+1
        right = len(nums)-1
        if i>0 and nums[i] == nums[i-1]:
            continue
        while left<right:
            c = nums[i]+nums[left]+nums[right]
            if c == 0:
                res.append([nums[i], nums[left], nums[right]])
                while nums[right] == nums[right-1] and right>left:
                    right -= 1
                while nums[left] == nums[left+1] and right>left:
                    left += 1
                left +=1
                right -= 1
            elif c>0:
                right -= 1
            else:
                left += 1
    return res

'''
def threeSum(nums):
    n=len(nums)
    res=[]
    if(not nums or n<3):
        return []
    nums.sort()
    res=[]
    for i in range(n):
        if(nums[i]>0):
            return res
        if(i>0 and nums[i]==nums[i-1]):
            continue
        L=i+1
        R=n-1
        while(L<R):
            if(nums[i]+nums[L]+nums[R]==0):
                res.append([nums[i],nums[L],nums[R]])
                while(L<R and nums[L]==nums[L+1]):
                    L=L+1
                while(L<R and nums[R]==nums[R-1]):
                    R=R-1
                L=L+1
                R=R-1
            elif(nums[i]+nums[L]+nums[R]>0):
                R=R-1
            else:
                L=L+1
    return res

if __name__ == "__main__":
    nums =  [-1, 0, 1, 2, -1, -4]
    a = threeSum(nums)
    print(a)
