'''
def largestRectangleArea(heights):
    n = len(heights)
    heights = heights+[0]
    stack = [-1]
    max_area = 0
    for i in range(n+1):
        while heights[i]<heights[stack[-1]]:
            h = heights[stack.pop()]
            w = i - stack[-1] - 1
            max_area = max(max_area, h*w)
        stack.append(i)
    return max_area

def subsetsWithDup(nums):
    nums.sort()
    n = len(nums)
    res = []
    def dfs(index, path):
        if path not in res:
            res.append(path)
        for i in range(index, n):
            dfs(i+1, path+[nums[i]])
    dfs(0, [])
    return res

if __name__ == "__main__":
    nums = [1,2,2]
    a = subsetsWithDup(nums)
    print(a)

'''

class TreeNode:
    def __init__(x):
        val = x
        left = None
        right = None
def isValidBST(root):
    if not root:
        return True
    res = []
    def ValidBST(root):
        if not root.left and not root.right and not root:
            if root.right.val>root.val > root.left.val:
                res.append(True)
            else:
                res.append(False)
        if root.left:
            ValidBST(root.left)
        if root.right:
            ValidBST(root.right)
    ValidBST(root)
    return all(res)

if __name__ == "__main__":
    n1 = TreeNode,n1.val = 5
    n2 = TreeNode,n2.val = 1
    n3 = TreeNode,n3.val = 4
    n4 = TreeNode,n4.val = 3
    n5 = TreeNode,n5.val = 6