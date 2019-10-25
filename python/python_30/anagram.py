
'''
# 检测两个字符串是否是属于字符串颠倒
# 导入collections 模块
from collections import Counter   
 
def anagram(first, second):    
    return Counter(first) == Counter(second)    

# 只要两个字符串具有相同长度，且每个字符数量一致返回True
print (anagram("abcd3", "3acdb"))
print (anagram("abcdf", "acdbe"))
print (anagram("123asd", "312sad"))

def square(x):
    return x**2

# a = list(map(square,[1,2,3,4]))

a = list(map(lambda x: x**2,[1,2,3,4]))
print(a)


print(math.ceil(3.1))
print(math.ceil(3.3))
print(math.ceil(3.5))
print(math.ceil(3.9))
print(math.ceil(3.0))
print(math.ceil(3))

import math 
lst = [1,2,3,4,5]
size = 2

a = [0,1,2]

b = list(
        map(
            lambda x: lst[x * size:x * size + size],a
        ))
print(b)    

def compact(lst):
    return list(filter(bool,lst))

b = compact([0,1,False,2,3,'a','s',34,None,0,1])
print(b)

def isodd(lit):
   return lit%2 == 1 

new = list(filter(isodd,[1,2,3,4,5,6,7,8]))
print(new)
'''
import math
def is_sqr(n):
    return math.sqrt(n)%1==0

new = list(filter(is_sqr,range(1,101)))
print(new)