
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
'''
s = '   12'
s = s.strip()
if not s:
    print('0')
