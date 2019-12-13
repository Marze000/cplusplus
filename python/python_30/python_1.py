'''
a = 10
num = ''.join(bin(a))
# print(list(num[::-1]))

n = 10
m = '{0:032b}'.format(n)[::-1]
print(m)
print(int(m, 2))


nums = [1, 2, 3, 4, 5]
num = nums[0:5:2]
print(num)

'''
a = 'aac'
b = 'dde'
c = set(zip(a, b))
print(list(c))
