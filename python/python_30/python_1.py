def trailingZeroes(n):
    def trailing(n):
        if n == 1:
            return 1
        return n*trailing(n-1)
    temp = trailing(n)
    lit = list(''.join(str(temp)))
    count = 0
    while lit.pop(-1) == 0:
        count += 1
    return count


if __name__ == "__main__":
    n = 5
    a = trailingZeroes(n)
    print(a)
