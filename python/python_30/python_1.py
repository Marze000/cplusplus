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


'''


dit = {'123': 10, '2': 20, '3': 30}
a = '123'
print(dit.get(a, [123]))
