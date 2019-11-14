def permute(nums):
    res = []
    def defs(num,path):
        if not num:
            res.append(path)
            return
        for i in range(len(num)):
            numss = num[:i]+num[i+1:]
            defs(numss,path+[num[i]])
    defs(nums,[])
    return res

if __name__ == "__main__":
    num = [1,2,3,4,5]
    print(permute(num))