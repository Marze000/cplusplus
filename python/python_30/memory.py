
# 检查对象的内存使用情况
# chars ='aaa'
# print(sys.getsizeof(variable))
# print('10占的字节数:',sys.getsizeof(10))

# print('字符aaa字节数:',sys.getsizeof(chars))
# 下面类型在 Python 中占 400 字节
'''
print(sys.getsizeof(int))
print(sys.getsizeof(float))
print(sys.getsizeof(list))
print(sys.getsizeof(dict))
print(sys.getsizeof(set))
n = 3
s = 'python'
rint(s * n)
s = '   12'
s = s.strip()
if not s:
    print('0')

def letterCombinations(self, digits):
    dic = {
        '2':['a', 'b', 'c'],
        '3':['d', 'e', 'f'],
        '4':['g', 'h', 'i'],
        '5':['j', 'k', 'l'],
        '6':['m', 'n', 'o'],
        '7':['p', 'q', 'r', 's'],
        '8':['t', 'u', 'v'],
        '9':['w', 'x', 'y', 'z']
    }
    result = []
    tail = []
    len_d = len(digits)
    if len_d == 0:
        return tail
    if len_d == 1:
        return dic[digits]
    
    tail = self.letterCombinations(digits[1:])
    for i in dic[digits[0]]:
        for j in tail:
            result.append(i+j)
    return result
            
def isValid(s):
    while '{}' in s or '()' in s or '[]' in s:
        s = s.replace('{}', '')
        s = s.replace('[]', '')
        s = s.replace('()', '')
    return s == ''
if __name__ == "__main__":
    s = '{[([])]}'
    print(isValid(s))

def generateParenthesis(n):
    def generator(left, right, s, res):
        if left<0 or right<0 or left>right:
            return
        if left==0 and right==0:
            res.append(s)
        generator(left-1, right, s+'(', res)
        generator(left, right-1, s+')', res)
    res = []
    generator(n, n, '', res)
    return res

    if n == 0:
        return [""]
    elif n == 1:
        return ["()"]
    elif n == 2:
        return ["()()", "(())"]
    result = []
    for i in range(n):
        j = n - 1 - i
        temp1 = self.generateParenthesis(i)
        temp2 = self.generateParenthesis(j)
        result.extend(["(%s)%s" % (p, q) for p in temp1 for q in temp2])
    return result

temp1=['']
temp2 = ['()()','(())']
print(["(%s)%s" % (p, q) for p in temp1 for q in temp2])
lists = ['0','1,2,3','4','7,8,9']
print(len(lists))
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        if head==None:
            return None
        if head.next == None:
            return head
        Headret = head
        first = head
        second = head.next
        thrid = second.next
        while second!=None:
            second.next = first
            if thrid==None:
                break
            first.next = thrid.next
            first = thrid
            second = thrid.next
            thrid = second.next
        return Headret

def swapPairs(self, head):
    if not head or not head.next:
        return head

    new_start = head.next.next
    head, head.next = head.next, head
    head.next.next = self.swapPairs(new_start)
    return head
    """
    :type head: ListNode
    :rtype: ListNode
"""

ListNode* swapPairs(ListNode* head) {
    if(head==NULL || head->next==NULL)
        return head;

    ListNode* p1=head;
    ListNode* p2=head->next;
    p1->next=p2->next;
    p2->next=p1;
    head=p2;
    
    p1=head->next;
    p2=p1->next;
    while(p2 && p2->next){
        ListNode* temp=p2->next->next;
        p1->next=p2->next;
        p2->next=temp;
        p1->next->next=p2;
        
        p1=p2;
        p2=p1->next;          
    }
    return head;       
}

def removeDuplicates(nums):
    if not nums:
        return 0
    i = 0
    for j in range(1, len(nums)):
        if nums[i]!=nums[j]:
            i += 1
            nums[i] = nums[j]
    return i+1

if __name__ == "__main__":
    nums = [1,1,2]
    print(removeDuplicates(nums))

# nums = [3,2,2,3], val = 3,
nums = [1,2,3,4,5,6,7,8,9]
for j in range(0, len(nums),2):            
    print(nums[j],end=' ')

def nextPermutation(nums):
    last = len(nums)-1
    left_last = last-1
    if nums[left_last]<nums[last]:
        nums[left_last],nums[last] = nums[last],nums[left_last]
        return
    if nums[left_last]>nums[last]:
        while left_last >= 0 and nums[left_last]>nums[last]:
            left_last-=1
        j = left_last-1
        if j >=0:
            nums[left_last],nums[last] = nums[last],nums[left_last]
            l = left_last+1
            r = len(nums)-1
        while l<r:
            nums[l],nums[r]=nums[r],nums[l]
            l+=1
            r-=1
        
if __name__ == "__main__":
    nums = [2,3,1]
    nextPermutation(nums)
    print(nums)

def searchInsert(nums, target):
    left = 0
    right = len(nums)
    while left<right:
        mid = (left+right)//2
        if nums[mid]>=target:
            right = mid
        else:
            left = mid + 1
    return left 

if __name__ == "__main__":
    nums = [1,3,5,6]
    searchInsert(nums,0)

def combinationSum(candidates, target):
    length = len(candidates)
    res = []
    
    def combinationSum_in(target,index,maybe):
        if target<0:
            return
        if target==0:
            res.append(maybe)
        
        for i in range(index,length):
            combinationSum_in(target-candidates[i],i,maybe+[candidates[i]])
                    
    combinationSum_in(target,0,[])
    return res

if __name__ == "__main__":
    candidates = [2,3,5]
    target = 8
    a = combinationSum(candidates, target)
    print(a)


def combinationSum2(candidates, target):
    c = sorted(candidates)
    res = []
    len_c = len(c)
    def dfs(target, index, path):
        if target == 0:
            res.append(path)
            return
        for i in range(index, len_c):
            if i>index and c[i] == c[i-1]:
                continue
            if c[i]>target:
                break
            dfs(target-c[i], i+1, path+[c[i]])
    dfs(target, 0, [])
    return res

if __name__ == "__main__":
    candidates = [2,5,2,1,2]
    target = 5
    a = combinationSum2(candidates, target)
    print(a)
import itertools
nums = [1,2,3]
a = list(itertools.permutations(nums))

print(a)


'''
def permute(nums):
    res = []
    def dfs(num, path):
        if not num:
            res.append(path)
            return
        for i in range(len(num)):
            numss = num[:i]+num[i+1:]
            dfs(numss, path+[num[i]])
    dfs(nums, [])
    return res 
if __name__ == "__main__":
    num = [1,2,3]
    a = permute(num)
    print(a)