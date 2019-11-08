# 判断年份是不是闰年
x = int(input('请输入年份：')) 

if x%400 == 0 or x%4==0 and x%100 != 0:
    print("{0}年是闰年".format(x)) 
else :
    print("{0}年不是是闰年".format(x)) 