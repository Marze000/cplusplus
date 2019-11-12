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
        
    num = int(num)*sign
    INT_MAX = 2**31
    return min(max(num,-1*INT_MAX), INT_MAX-1)

if __name__ == "__main__":
    str = '    -42'
    a = myAtoi(str)
    print(a)

def isPalindrome(self, x):
    x = str(x)
    return x == x[::-1]

def maxArea(height):
    if not len(height):
        return 0
    max_s = 0
    for i in range(len(height)):
        for j in range(i+1,len(height)):
            s = min(height[i],height[j])*(j-i)
            if s > max_s:
                max_s = s
    return max_s

def maxArea(height):
    if not len(height):
        return 0
    start = 0
    end = len(height)-1
    max_s = 0
    while start < end:
        s = min(height[start],height[end])*(end-start)
        if s > max_s:
            max_s = s
        if height[start]<height[end]:
            start+=1
        else:
            end-=1
    return max_s
def longestCommonPrefix(strs):
    ret = ''
    if not len(strs):
        return ret
    j = 0
    falg = 1
    for i in range(len(strs[0])):
        for j in range(len(strs)):
            if strs[j][i] != strs[j+1][i]:
                falg = 0
            ret += strs[j][i]
    if falg:
        return ret
    else:
        return ''

    sample = strs[0]
    for i in range(len(sample)):
        for s in strs[1:]:
            if i<len(s) :
                if s[i]!=sample[i]:
                    return sample[:i]
            else:
                return s[:i]
    return sample

if __name__ == "__main__":
    a = ["flower","flow","flight"]
    s1 = min(a)
    s2 = max(a)
    print(s1,s2)
    # print(a[1:])
    # print(longestCommonPrefix(a))


# coding:utf-8
from appium import webdriver
import time, os
 
def test_call_number():
    # number是个列表，直接在这里天上你想要骚扰的号码即可
    number = []
    # 直接一个for循环，循环号码
    for num in number:
        # 使用adb打电话
        call = os.popen('adb shell am start -a android.intent.action.CALL -d tel:%s' % num)
        # 这里的sleep时间基本就是你想让通话保持的时间了
        time.sleep(10)
        #挂断电话
        end = os.popen('adb shell input keyevent 6') # code6是挂断
        time.sleep(4)
 
if __name__ == '__main__':
    test_call_number()

# Download the helper library from https://www.twilio.com/docs/python/install
from twilio.rest import Client


# Your Account Sid and Auth Token from twilio.com/console
# DANGER! This is insecure. See http://twil.io/secure
account_sid = 'AC3ecb5c84848a200da545bf1dfb8ab9e7'
auth_token = 'your_auth_token'
client = Client(account_sid, auth_token)

 
# 开始发短信
def send_msg(message):
    u'自定义短信内容message'
    msg = client.messages.create(
        to='+8618729502326',  # 要给谁发短信, 必须带区号, 中国要加上+86
        from_='+12013351008', # 你自己twilio网站申请的手机号码, 必须带上+号
        body=message  # 你的短信内容
    )
 

if __name__ == '__main__':
    send_msg('haha')


import itchat
# 自动登录方法，hotReload=True可以缓存，
# 不用每次都登录,但是第一次执行时会出现一个二维码，
# 需要手机微信扫码登录
itchat.auto_login(hotReload=True)

# 搜索好友，search_friends("xxx"),
# 其中"xxx"为好友昵称，备注或微信号不行
userfinfo = itchat.search_friends("boy")   # "智能群管家014"为好友昵称

# print(userfinfo)，获取userinfo中的UserName参数
userid = userfinfo[0]["UserName"]   # 获取用户id

# 调用微信接口发送消息
itchat.send("hello dear", userid)  # 通过用户id发送信息
# 使用微信接口给微信好友发送消息，

'''
num = [1,2,3]
for i in range(len(num)):
    print(num[:i]+num[i+1:])
 