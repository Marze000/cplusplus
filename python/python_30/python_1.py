'''
a = 10
num = ''.join(bin(a))
# print(list(num[::-1]))
'''

n = 10
m = '{0:032b}'.format(n)[::-1]
print(m)
print(int(m, 2))
