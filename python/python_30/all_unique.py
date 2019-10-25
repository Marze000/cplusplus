
'''
# 判断列表中是否有重复的元素
def all_unique(lit):
    #如果没有重复的元素返回 True
    # set 的作用是给列表去重
    return len(lit) == len(set(lit))

x = (1,2,3,4,5,2,5,6)

for i in x:
    if x.count(i) > 1:
        print(i)
        break
'''

