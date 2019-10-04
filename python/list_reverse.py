# 逆置数组
# 将 3 * 4 的矩阵转换为 4 * 3 的矩阵
matrix =[
    [1,2,3,4],
    [3,4,5,6],
    [5,6,7,8]
]

# 方法一
for i in range(len(matrix[0])):
    print('[',end="")
    for row in matrix:
        print(row[i],end=" ")
    print(']')

# 方法二
list = [[row[i] for row in matrix] for i in range(4)]
print(list)

# 方法三
transposed = []
for i in range(4):
    transposed.append([row[i] for row in matrix])

print(transposed)

# 方法四
trans = []
for i in range(4):
    transposed_row = []
    for row in matrix:
        transposed_row.append(row[i])
    trans.append(transposed_row)
print(trans)