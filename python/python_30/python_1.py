def levelOrder(self, root):
    if not root:
        return []
    res, level = [], [root]
    while level:
        res.append([node.val for node in level])
        LR_pair = [(node.left, node.right) for node in level]
        level = [leaf for LR in LR_pair for leaf in LR if leaf]   
    return res
