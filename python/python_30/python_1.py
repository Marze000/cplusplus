import math
import collections

'''
s = [2, 5, 8, 3, 6, 9]
for index,num in enumerate(s, 1):
    print(index,num)

def minWindow(s, t):
    n = len(s)
    res = ''
    min_length = n
    for i in range(n):
        temp = list(t)
        for j in range(i, n):
            if s[j] in temp:
                temp.remove(s[j])
            if len(temp) == 0:
                if j-i <= min_length:
                    min_length = j-i
                    res = s[i:j+1]
                break
    return res


if __name__ == "__main__":
    S = "cabwefgewcwaefgcf"
    T = "cae"
    s = minWindow(S, T)
    print(s)



def minWindow(s, t):
    need = collections.Counter(t)
    missing = len(t)
    start, end = 0, 0
    left = 0
    for right, char in enumerate(s, 1):
        if need[char] > 0:
            missing -= 1
        need[char] -= 1
        if missing == 0:
            while left < right and need[s[left]] < 0:
                need[s[left]] += 1
                left += 1
            need[s[left]] += 1
            missing += 1
            if end == 0 or right-left < end-start:
                start, end = left, right
            left += 1
    return s[start:end]


if __name__ == "__main__":
    s = "ADOBECODEBANC"
    t = "ABC"
    minWindow(s, t)

'''
nums = [1, 2, 3]
dp = [[]]
for num in nums:
    for item in dp:
        dp = dp + [item+[num]]

print(dp)
