'''
def combinationSum(candidates, target):
    length = len(candidates)
    res = []

    def combinationSum_in(target, index, maybe):
        if target < 0:
            return
        if target == 0:
            res.append(maybe)

        for i in range(index, length):
            combinationSum_in(target-candidates[i], i, maybe+[candidates[i]])

    combinationSum_in(target, 0, [])
    return res

if __name__ == "__main__":
    candidates = [2, 3, 5]
    target = 8
    print(combinationSum(candidates, target))

'''


def trap(height):
    max_left = [0]
    for h in height:
        max_left.append(max(max_left[-1], h))
    max_right = 0
    res = 0
    n = len(height)
    for i in range(n):
        max_right = max(max_right, height[n-i-1])

        res += min(max_right, max_left[n-i]) - height[n-i-1]
    return res


if __name__ == "__main__":
    height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
    trap(height)
