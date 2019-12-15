def shortestPalindrome(s):
    r = s[::-1]
    for i in range(len(s) + 1):
        # startswith() 方法用于
        # 检查字符串是否是以指定子字符串开头
        # 如果是则返回 True，否则返回 False
        if s.startswith(r[i:]):
            return r[:i] + s
if __name__ == "__main__":
    s = abcd
    a = shortestPalindrome(s)
    print(a)
