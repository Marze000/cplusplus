'''
# 以字节为单位返回字符串的长度

def byte_size(string):
    # encode 就是以某种编码格式对字符串进行编码
    # decode 是针对encode 编码后的字符串进行解码
    return (len(string.encode('utf-8')))

print(byte_size('10'))
print(byte_size('hello pyhton'))
print(byte_size('哈哈'))


# for example
s = '喜欢你'
print(s)
s_utf8 = s.encode('utf-8')
print(s_utf8)# b'/.../.../.../../.../...
print(s_utf8.decode('utf-8'))# 喜欢你

#-------------------------------------------------------
# 重复打印字符串
n = 2
s = 'program'
print(s*n)

#-------------------------------------------------------
# 首字母大写 每一个单独的单词的首字母都会被改为大写
s = 'program is a word'
print(s.title())
# 值得注意是: 他会将其不是首字母的字符改为小写
ss = 'JHKJAHD dhasSA dahkHDA'
print(ss.title())

'''

#-------------------------------------------------------
from math import ceil 
# 将列表分块分为指定大小的较小列表
def chunk(lst, size):    
    return list(
        map(
            lambda x: lst[x * size:x * size + size],
            list(range(0, ceil(len(lst) / size)))
        )
    )    

print(chunk([1,2,3,4,5],2)) # [[1,2],[3,4],[5]]
