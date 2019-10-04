import math

cal_range = int(input('请输入计算质数的范围：'))
prime_nums = []

for i in range(cal_range+1):
    if i == 0 or i == 1:
        continue

    num = 2
    while num <= math.sqrt(i):
        if i % num == 0:
            break
        else:
            num += 1

    if num > math.sqrt(i):
        prime_nums.append(i)

for i in prime_nums:
    print(i)
