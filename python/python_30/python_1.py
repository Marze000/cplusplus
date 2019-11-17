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
'''


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
