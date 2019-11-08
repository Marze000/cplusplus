dict = {'maze':1998,'hhee':2000,'hhaa':2001}
for i, j in dict.items():
    print(i,j)

# 其中 i 为索引位置  
for i,v in enumerate(['000','aaa','bbb','ccc']):
    # v 为列表中的值
    print(i,v)

# 同时遍历两个序列或多个序列
questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
    print('What is your {0}?  It is {1}.'.format(q, a))

for i in reversed(range(1,10,2)):
    print(i,end=" ")
print('\n')
for i in reversed(range(0,10,2)):
    print(i,end=" ")

basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']
# set 去重
for f in sorted(set(basket)):
    print(f)
