# 编写程序，用户从键盘输入小于1000的整数，对其进行因式分解。
# 例如，10=2×5，60=2×2×3×5。

num = int(input('输入一个数字'))
print ('{0}='.format(num))
i = 2
while i <= num:
    while num % i == 0:
        num = num/i
        print (i)
        if num != 1:
            print ('x')
        else:
            break
    i += 1


