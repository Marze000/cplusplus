
# 检查对象的内存使用情况
# chars ='aaa'
# print(sys.getsizeof(variable))
# print('10占的字节数:',sys.getsizeof(10))

# print('字符aaa字节数:',sys.getsizeof(chars))
# 下面类型在 Python 中占 400 字节
'''
print(sys.getsizeof(int))
print(sys.getsizeof(float))
print(sys.getsizeof(list))
print(sys.getsizeof(dict))
print(sys.getsizeof(set))
n = 3
s = 'python'
rint(s * n)
s = '   12'
s = s.strip()
if not s:
    print('0')

def letterCombinations(self, digits):
    dic = {
        '2':['a', 'b', 'c'],
        '3':['d', 'e', 'f'],
        '4':['g', 'h', 'i'],
        '5':['j', 'k', 'l'],
        '6':['m', 'n', 'o'],
        '7':['p', 'q', 'r', 's'],
        '8':['t', 'u', 'v'],
        '9':['w', 'x', 'y', 'z']
    }
    result = []
    tail = []
    len_d = len(digits)
    if len_d == 0:
        return tail
    if len_d == 1:
        return dic[digits]
    
    tail = self.letterCombinations(digits[1:])
    for i in dic[digits[0]]:
        for j in tail:
            result.append(i+j)
    return result
            
def isValid(s):
    while '{}' in s or '()' in s or '[]' in s:
        s = s.replace('{}', '')
        s = s.replace('[]', '')
        s = s.replace('()', '')
    return s == ''
if __name__ == "__main__":
    s = '{[([])]}'
    print(isValid(s))

def generateParenthesis(n):
    def generator(left, right, s, res):
        if left<0 or right<0 or left>right:
            return
        if left==0 and right==0:
            res.append(s)
        generator(left-1, right, s+'(', res)
        generator(left, right-1, s+')', res)
    res = []
    generator(n, n, '', res)
    return res

    if n == 0:
        return [""]
    elif n == 1:
        return ["()"]
    elif n == 2:
        return ["()()", "(())"]
    result = []
    for i in range(n):
        j = n - 1 - i
        temp1 = self.generateParenthesis(i)
        temp2 = self.generateParenthesis(j)
        result.extend(["(%s)%s" % (p, q) for p in temp1 for q in temp2])
    return result

temp1=['']
temp2 = ['()()','(())']
print(["(%s)%s" % (p, q) for p in temp1 for q in temp2])
'''
lists = ['0','1,2,3','4','7,8,9']
print(len(lists))
