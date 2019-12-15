def maximalSquare(matrix):
    if not len(matrix) or not len(matrix[0]):
        return 0
    b,row,col = 0,len(matrix)+1,len(matrix[0])+1
    res = [[0]*row for _ in range(col)]
    for i in range(1,row):
        for j in range(1,col):
            if matrix[i-1][j-1]=='1':
                res[i][j] = min(res[i-1][j-1],res[i-1][j],res[i][j-1])+1
                b = max(b,res[i][j])
    return b**2
if __name__ == "__main__":
    matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    a = maximalSquare(matrix)
    print(a)
