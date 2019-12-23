def uncommonFromSentences(A, B):
    dic = {}
    temp = A.split()+B.split()
    for s in temp:
        if s not in dic:
            dic[s] = 1
        else:
            dic[s] += 1
    res = []
    for key, value in dic.items():
        if value == 1:
            res.append(key)
    return res


if __name__ == "__main__":
    A = "this apple is sweet"
    B = "this apple is sour"
    a = uncommonFromSentences(A, B)
    print(a)
