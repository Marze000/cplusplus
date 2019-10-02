# 坚持两个字符串是否是属于字符串颠倒

# 导入collections 模块
from collections import Counter   
 
def anagram(first, second):    
    return Counter(first) == Counter(second)    

# 只要两个字符串具有相同长度，且每个字符数量一致返回True
print (anagram("abcd3", "3acdb"))
print (anagram("abcdf", "acdbe"))
print (anagram("123asd", "312sad"))