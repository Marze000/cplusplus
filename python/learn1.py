# 求第 n 项斐波那契数列
a,b = 1,1
n = int(input('请输入计算的斐波那契数列'))
while n-2:
    a ,b = b,a+b
    n = n-1
print(b)