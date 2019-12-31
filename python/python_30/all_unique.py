'''
def kthSmallest(matrix, k):
    n, m = len(matrix), len(matrix[0])
    l, h = matrix[0][0], matrix[n-1][m-1]
    while l < h:
        count = 0
        mid = l + (h-l)//2
        for i in range(n):
            j = m-1
            while j >= 0 and matrix[i][j] > mid:
                j -= 1
            count += j+1
            print(count, k)
        if count >= k:
            h = mid
        else:
            l = mid + 1
    return l


if __name__ == "__main__":
    matrix = [
        [1, 5, 9],
        [10, 11, 13],
        [12, 13, 15]
    ]
    k = 8
    a = kthSmallest(matrix, k)
    print(a)

'''
s = 'abcde'
s = list(s)
print(s)
