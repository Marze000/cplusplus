'''
import time

# 格式为: Fri Oct 25 13:04:42 2019
time.asctime(time.localtime(time.time()))

# 时间戳格式
localtime = time.time()

#当然格式也可以自己初始化 例如下面：
# 格式为 2019-10-25 12:20:34 的形式
time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())

Time = time.strftime("%y-%m-%d",time.localtime())
# print(Time)
%a 代表的是星期几
%A 完整的星期几
%H 是二十四小时
%l 是十二小时计数法
%b 月份
%j 一年中的第几天
%Z 当前的时区名称

import calendar
cal = calendar.month(1998,9)
# print('1998年9月的日历')
# print(cal)
x = -10
print(abs(x))

print(divmod(10,2))

a = 10
b = 4
print(a/b) 
print(a//b)
print(a%b)

# a = input('请输入一个数字')

a = input("input:")
print(type(a))
print(a)
'''
al = all([1,2,3,0,4])
print(al) # Flase

bl = all((1,2,None,4))
print(bl) # False

a = [1,2,3,4,5,0,6]
if all(a) == True:
    print('数组a 中没有空值或者None')
else:
    print('在数组中存在空值或0')
