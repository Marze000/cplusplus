import collections

# 判断数组中的数字是否超过了数组个数的一半
def MoreThanHalfNum_Solution(numbers):
    tmp = collections.Counter(numbers)
    print(tmp)
    x = len(numbers)/2
    for k, v in tmp.items():
        if v > x:
            return k
    return 0

def PrintMinNumber(self, numbers):
    if not numbers:
        return ""
    lmb = lambda n1, n2:int(str(n1)+str(n2))-int(str(n2)+str(n1))
    array = sorted(numbers, cmp=lmb)
    return ''.join([str(i) for i in array])


lmb = lambda n1, n2:int(str(n1)+str(n2))-int(str(n2)+str(n1))
numbers = [12,34,56,78]
array = sorted(numbers,cmp = lmb)
print(array)

if __name__ == "__main__":
    #numbers = [1,2,2,2,2,3,4]
    #a = MoreThanHalfNum_Solution(numbers)
    #print(a)
