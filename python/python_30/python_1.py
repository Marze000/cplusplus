'''
def generate(numRows):
    if numRows <= 0:
        return []
    res = []
    for i in range(1, numRows):
        temp = []
        for j in range(i):
            if j == 0 or j == i-1:
                temp.append(1)
            else:
                t = res[i-2][j]+res[i-2][j-1]
                temp.append(t)
        res.append(temp)
    return res


if __name__ == "__main__":
    numRows = 5
    a = generate(numRows)
    print(a)

# 计算平方数
def square(x):
    return x ** 2
# 计算列表各个元素的平方
a = map(square, [1, 2, 3, 4, 5])
print(list(a))


# 使用 lambda 匿名函数
a = map(lambda x: x ** 2, [1, 2, 3, 4, 5])
print(list(a))

# 提供了两个列表，对相同位置的列表数据进行相加
a = map(lambda x, y: x + y, [1, 3, 5, 7, 9], [2, 4, 6, 8, 10])
print(list(a))

res = [[1, 3, 3, 1]]
res.append(list(map(lambda x, y: x+y, res[-1] + [0], [0] + res[-1])))
print(res)

a = [1, 2, 3, 4, 5]
b = [1, 3, 5, 7, 9]
c = zip(a, b)
print(list(c))

def isPalindrome(s):
    if len(s)==0:
        return True
    res = ''
    for i in s:
        # isalpha判断是否字母
        if i.isalpha():
            res+=i 
    # 转换大小为小写
    res = res.lower()
    return res==res[::-1]
if __name__ == "__main__":
    s = 'OP'
    a = isPalindrome(s)
    print(a)
    
'''
a = '12345'
res = '@'.join(a)
print(res)
