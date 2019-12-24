def wordPattern(pattern, str):
    s = str.split()
    temp = {}
    pattern = ' '.join(pattern)
    pattern = list(pattern)
    if len(set(pattern)) != len(set(s)):
        return False
    for i in range(len(pattern)):
        if pattern[i] not in temp:
            temp[pattern[i]] = s[i]
        else:
            if s[i] != temp[pattern[i]]:
                return False
    return True


if __name__ == "__main__":
    pattern = "abba"
    str = "dog cat cat dog"
    a = wordPattern(pattern, str)
    print(a)
