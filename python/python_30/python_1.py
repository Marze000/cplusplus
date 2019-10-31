#  给定 nums = [2, 7, 11, 15], target = 9 
#  因为 nums[0] + nums[1] = 2 + 7 =9 
#  所以返回 [0, 1]

'''
用字典保存遍历过的数字和下标
寻找target-nums[i]是否在字典中出现过，是则返回两数的下标
否则存入nums[i]及其下标
def twoSum(nums, target):
    dict = {}
    for i in range(len(nums)):
        if target-nums[i] in dict:
            return [dict[target-nums[i]], i]
        else:
            dict[nums[i]] = i

if __name__ == "__main__":
    nums = [2,7,11,15]
    target = 18
    print(twoSum(nums,target))

res = []
def find_two(nums,target):
    nums.sort()
    i = 0
    j = len(nums)-1
    while i < len(nums) and j >=0:
        if nums[i] + nums[j] == target:
            res.append(i)
            res.append(j)
            return res
        elif nums[i] + nums[j] > target:
            j = j - 1
        else:
            i = i + 1

if __name__ == "__main__":
    nums = [2,7,11,15]
    target = 18
    print(find_two(nums,target))


class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

def addTwoNumbers(l1, l2):
    dummy = ListNode(0)
    cur = dummy
    carry = 0
    while l1 or l2:
        num1 = l1.val if l1 else 0
        num2 = l2.val if l2 else 0
        sum = num1 + num2 + carry
        
        carry = sum // 10 # 取余数
        cur.next = ListNode(sum%10)
        cur = cur.next
        l1 = l1.next if l1 else None
        l2 = l2.next if l2 else None
    if carry:
        cur.next = ListNode(carry)
    return dummy.next

if __name__ == "__main__":
    l1 = ListNode(2)
    p1 = ListNode(4)
    p2 = ListNode(3)
    l2 = ListNode(5)
    m1 = ListNode(6)
    m2 = ListNode(4)
    l1.next = p1
    p1.next = p2
    p2.next = None
    l2.next = m1
    m1.next = m2
    m2.next = None
    addTwoNumbers(l1, l2)

def lengthOfLongestSubstring (s):
    max = 0
    for i in range(len(s)):
        count = 0
        ss = ''
        j = i
        while j < len(s):
            if s[j] not in ss:
                ss +=s[j]
                count+=1
                if count > max:
                    max = count
                j +=1
            else:
                break
    return max

if __name__ == "__main__":
    s = 'pwwkew'
    a = lengthOfLongestSubstring(s)
    print(a)

# 利用正则表达式
import re
pattern = re.compile(ur'^[-+]?\d*(?:\.\d*)?(?:[eE][+\-]?\d+)?$')
str = u''
if pattern.search(str):
    return True
else:
    return False
return re.match(r"^[\+\-]?[0-9]*(\.[0-9]*)?([eE][\+\-]?[0-9]+)?$",s)

def lengthOfLongestSubstring(s):
        start = 0
        usedChar = {}
        max_len = 0
        for i in range(len(s)):
            if s[i] in usedChar and usedChar[s[i]>=start]:
                start = usedChar[s[i]] + 1
            else:
                max_len = max(max_len, i-start+1)                              
            usedChar[s[i]] = i
        return max_len


def findMedianSortedArrays(nums1, nums2):
        sum = 0
        if len(nums1) & 1:
            sum = nums1[len(nums1)//2]
        elif len(nums1) != 0:
            a1 = nums1[len(nums1)//2]
            a2 = nums1[(len(nums1)//2)-1]
            sum = (a1 + a2)/2
        else:
            sum = 0

        if len(nums2) & 1:
            sum += nums2[len(nums2)//2]
        elif len(nums2)!=0:
            a1 = nums2[len(nums2)//2]
            a2 = nums2[(len(nums2)//2)-1]
            sum += (a1 + a2)/2
        else:
            sum +=0
        return sum/2

if __name__ == "__main__":
    num1 = []
    num2 = [1]
    print(findMedianSortedArrays(num1, num2))

def longestPalindrome(self, s):
    def expand(s, left, right):
        while left>=0 and right<len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right-left-1
    start = 0
    end = 0
    for i in range(len(s)):
        len1 = expand(s, i, i)
        len2 = expand(s, i, i+1)
        max_len = max(len1, len2)
       
        if max_len > end - start:
            start = i - (max_len-1)/2
            end = i + max_len/2
    return s[start:end+1]
''' 


'''
def longestPalindrome(self, s):
    def expand(s, left, right):
        while left>=0 and right<len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right-left-1
    start = 0
    end = 0
    for i in range(len(s)):
        len1 = expand(s, i, i)
        len2 = expand(s, i, i+1)
        max_len = max(len1, len2)
        if max_len > end - start:
            start = i - (max_len-1)/2
            end = i + max_len/2
    return s[start:end+1]

def longestPalindrome(s):
    start = 0
    end = 0
    for i in range(len(s)):
        len1 = expend(s,i,i)
        len2 = expend(s,i,i+1)
        len_max = max(len1,len2)

        if len_max > end-start:
            start = i-len1//2
            end = i+len1//2
    return s[start:end+1]       

def expend(s,left,right):
    while left>=0 and right<len(s) and s[left]==s[right]:
        left -=1
        right+=1
    return right-left-1

def longestPalindrome(s):
    if not s:
        return ""

    s_len = len(s)
    mem = [[0]*s_len for _ in range(s_len)]

    left, right, result_len = 0, 0, 0
    for j in range(s_len):
        for i in range(j):
            if s[i] == s[j] and (j-i < 2 or mem[i+1][j-1]):
                mem[i][j] = 1
            if mem[i][j] and result_len < j-i+1:
                result_len = j - i + 1
                left, right = i, j
        
        mem[j][j] = 1
    return s[left:right+1]

if __name__ == "__main__":
    s = 'ababc'
    print(longestPalindrome(s))
def reverse(x):
    sign = 1 if x > 0 else -1
    # 去掉符号
    x = abs(x)
    s = str(x)
    s = s[::-1]
    ret = int(s) 
    if sign==-1:
        return 0-ret
    else:
        return ret

def reverse(x):
    s = str(x)[::-1].rstrip('-')
    if int(s) < 2**31:
        if x >=0:
            return int(s)
        else:
            return 0-int(s)
    return  0
###
def myAtoi(str):
    i = 0
    if len(str)==0:
        return 0
    while i<len(str) and str[i]==' ':
        i+=1

    if i < len(str) and not ('0'<=str[i]<='9' or str[i]=='+' or str[i]=='-'):
        return 0

    sign = ''
    if str[i] == '-':
        sign = '-'
        i +=1
    if str[i] == '+':
        sign = '+'
        i +=1

    while i<len(str) and '0'<=str[i]<='9':
        sign+=str[i]
        i+=1
    
    num = int(sign)
    if abs(num)<2**31:
        return num
    else:
        if num > 0:
            return 2147483647
        else:
            return -2147483648

'''
def myAtoi(str):
    s = str.strip()
    if not s:
        return 0
    sign = 1
    if s[0] == '-':
        sign = -1
        s = s[1:]
    elif s[0]=='+':
        s = s[1:]
    num = ''
    for c in s:
        if c.isdigit():
            num += c
        else:
            break
    if not num:
        return 0
    num = int(num)*sign

    if abs(num)<2**31:
        return num
    else:
        if num > 0:
            return 2**31-1
        else:
            return -2**31
        
    '''
    num = int(num)*sign
    INT_MAX = 2**31
    return min(max(num,-1*INT_MAX), INT_MAX-1)
    '''

if __name__ == "__main__":
    str = '    -42'
    a = myAtoi(str)
    print(a)