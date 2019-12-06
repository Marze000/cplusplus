res = []
a = "a good example"
s = a[::-1].split()
for i in s:
    res.append(i[::-1])
print(res)