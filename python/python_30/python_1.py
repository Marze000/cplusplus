'''
def intToRoman(num):
    # 代表 千分位单位
    M = ['', 'M', 'MM', 'MMM']
    # 代表 百分位单位
    C = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
    # 代表 十分位单位
    X = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
    # 代表 各分位单位
    I = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']

    a = M[num/1000]+C[num % 1000/100]+X[num % 100/10]+I[num % 10]
    return str(a)


if __name__ == "__main__":
    a = intToRoman(1314)
    print(a)
'''


import itertools
from collections import Counter


def intToRoman(num):
    M = ["", "M", "MM", "MMM"]
    '''
    C = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"]
    X = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"]
    I = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"]
    return M[num/1000]+C[(num%1000)/100]+X[(num%100)/10]+I[num%10]
    print(M[int(num/1000)])


if __name__ == "__main__":
    intToRoman(2345)


def romanToInt(s):
    a = {'I':1, 'V':5, 'X':10, 'L':50, 'C':100, 'D':500, 'M':1000}
    ans=0
    for i in range(len(s)):
        if i<len(s)-1 and a[s[i]]<a[s[i+1]]:
            ans-=a[s[i]]
        # M CM XC IV
        else:
            ans+=a[s[i]]
    return ans

if __name__ == "__main__":
    s = "III"
    print(romanToInt(s))


def longestValidParentheses(s):
    a = '()'
    max = 0
    if a in s:
        while a in s:
            max += 2
            s = s.replace('()', '', 1)
    return max


if __name__ == "__main__":
    s = "()(()"
    a = longestValidParentheses(s)
    print(a)



def search(nums, left, right, target):
    res = 0
    while left < right:
        mid = (left+right)//2
        if nums[mid] == target:
            res = mid
            break
        elif nums[mid] < target:
            left = mid+1
        else:
            right = mid
    return res


def searchRange(nums, target):
    if not nums:
        return [-1, -1]
    res = search(nums, 0, len(nums), target)
    l = r = res
    if l == 0 and nums[l] != target:
        return [-1, -1]
    if r == len(nums)-1 and nums[r] != target:
        return [-1, -1]

    if nums[l] == target:
        while l >= 0 and nums[l] == target:
            l -= 1
    if nums[r] == target:
        while r < len(nums) and nums[r] == target:
            r += 1

    return [l+1, r-1]


if __name__ == "__main__":
    nums = [0, 1, 2, 3, 4, 4, 4]
    target = 2
    a = searchRange(nums, target)
    print(a)

def search_border(nums, target, l, is_left):
    r = len(nums)
    while l<r:
        mid = (l+r)//2
        if nums[mid]>target or (is_left and target==nums[mid]):
            r = mid
        else:
            l = mid + 1
    return l

def searchRange(self, nums, target):
    left = search_border(nums, target, 0, True)
    if left==len(nums) or nums[left]!=target:
        return [-1,-1]

    right = search_border(nums, target, left, False) - 1
    return [left, right]



def groupAnagrams(strs):
    res = []
    for i in range(len(strs)):
        for j in range(i, len(strs)):
            if Counter(strs[i]) == Counter(strs[j]):
                res.append(strs[j])
            else:
                res.append(strs[j])
    print(res)


def groupAnagrams(strs):
    d = {}
    for s in strs:
        key = tuple(sorted(s))
        d[key] = d.get(key, []) + [s]
    return d.values()


if __name__ == "__main__":
    a = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(groupAnagrams(a))



def groupAnagrams(strs):
    d = {}
    for s in strs:
        # key 应该不可以是一个列表list ，所以进行tuple转换
        key = str(sorted(s))
        # get 函数是找出 key 键对应的值
        d[key] = d.get(key, []) + [s]
    return d.values()


if __name__ == "__main__":
    a = ["eat", "tea", "tan", "ate", "nat", "bat"]
    print(groupAnagrams(a))



dit = {'123': 10, '2': 20, '3': 30}
a = '123'
print(dit.get(a, [123]))

def maxSubArray(nums):
    maxnum = nums[0]
    res = nums[0]
    for i in range(1,len(nums)):
        if res>0:
            res+=nums[i]
        else:
            res = nums[i] 
        maxnum = max(res,maxnum)
    return maxnum

if __name__ == "__main__":
    nums = [-2,1]
    a = maxSubArray(nums)
    print(a)

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

def merge(intervals):
    if not intervals:
        return intervals
    intervals = sorted(intervals,  key=lambda x : x.start)
    res = [intervals[0]]
    for item in intervals[1:]:
        if item.start <= res[-1].end:
            res[-1].end = max(item.end, res[-1].end)
        else:
            res.append(item)
    return res
if __name__ == "__main__":
    nums = [[1,3],[2,6],[8,10],[15,18]]
    merge(nums)



def lengthOfLastWord(s):
    s = s.split()
    return len(s[-1])


if __name__ == "__main__":
    s = '  hello world   ma     '
    s = s.strip(' ')
    print(s)
    print(len(s))

def generateMatrix(n):
    res = [[0]*n for _ in range(n)]
    i, j, di, dj = 0, 0, 0, 1
    for k in range(1, n*n+1):
        res[i][j] = k
        if res[(i+di)%n][(j+dj)%n]:
            di, dj = dj, -di
        i += di
        j += dj
    return res

if __name__ == "__main__":
    a = generateMatrix(4)
    print(a)

import math
def getPermutation(n, k):
    kth = ''
    nums = list(map(str, range(1, n+1)))
    k -= 1
    while n>0:
        n -= 1
        f = math.factorial(n)
        index, k = divmod(k, f)
        kth += nums.pop(index)        
    return kth
if __name__ == "__main__":
    a = getPermutation(3,3)
    print(a)
    
# Definition for singly-linked list.
class ListNode:
    val = x
    next = None

def rotateRight(head,k):
    if not head or k==0:
        return head
    count = 0
    temp_count = head
    # 计算链表长度
    while temp_count != None:
        count+=1
        temp_count=temp_count.next
    # 如果k是链表长度的倍数则不翻转
    if k%count==0:
        return head

    # 找到该从哪个位置断开链表
    num = k%count
    cut = head
    n = count-num
    while n > 0:
        cut=cut.next
        n-=1
    ret = cut
    cut = None
    # 以下的任务是将 ret 的链表的尾部拼接到cut首部
    retlist = ret
    while ret.next !=None:
        ret=ret.next
    ret.next = head
    return retlist

if __name__ == "__main__":
    n1 = new ListNode
    n2 = new ListNode    
    n3 = new ListNode    
    n4 = new ListNode    
    n5 = new ListNode    

def uniquePathsWithObstacles(obstacleGrid):
    if obstacleGrid[0][0]==1:
        return 0
    row = len(obstacleGrid)
    col = len(obstacleGrid[0])
    if row ==1 or col ==1:
        return 1
    dp = [[0]*col for _ in range(row)]
    # 判断第一列的障碍
    for i in range(row):
        if obstacleGrid[i][0] == 1:
            break
        else:
            dp[i][0]=1
    for i in range(col):
        if obstacleGrid[0][i]==1:
            break
        else:
            dp[0][i]=1
    
    for i in range(1,row):
        for j in range(1,col):
            if obstacleGrid[i][j]==1:
                dp[i][j]=0
            else:
                dp[i][j] =dp[i-1][j]+dp[i][j-1]
    return dp[row-1][col-1]
            
if __name__ == "__main__":
    obstacleGrid = [[0,0],[1,1],[0,0]]
    a = uniquePathsWithObstacles(obstacleGrid)
    print(a)



def minPathSum(grid):
    row = len(grid)
    col = len(grid[0])
    if row == 0 or col == 0:
        return 0

    dp = [[0]*col for _ in range(row)]
    dp[0][0] = grid[0][0]
    # 初始化第一行的值
    for i in range(1,col):
        dp[i][0] = grid[i][0]+dp[i-1][0]
    # 初始化第一类的值
    for i in range(1,row):
        dp[0][i] = grid[0][i] + dp[0][i-1]

    for i in range(1, row):
        for j in range(1, col):
            dp[i][j] = grid[i][j] + min(dp[i][j-1], dp[i-1][j])
    return dp[row-1][col-1]


if __name__ == "__main__":
    grid = [[1, 3, 1], [1, 5, 1], [4, 2, 1]]
    a = minPathSum(grid)
    print(a)



a = [[1, 2], [3, 4], [5, 6]]
print(len(a))
print(len(a[0]))



import itertools
def permute(nums):
    a= list(itertools.permutations(nums))
    return a[2]


if __name__ == "__main__":
    a = permute([1, 2, 3])
    print(a)

'''