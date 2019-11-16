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
    '''
    print(M[int(num/1000)])


if __name__ == "__main__":
    intToRoman(2345)
