'''
递归
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        sum_ = 0
        path = []
        res = []
        if not root: return res
        def backtrack(root, targetSum):
            nonlocal sum_
            sum_ += root.val
            path.append(root.val)
            if not root.left and not root.right and sum_ == targetSum:
                res.append(path[:])
            if root.left:
                backtrack(root.left, targetSum)
            if root.right:
                backtrack(root.right, targetSum)
            sum_ -= root.val
            path.pop(-1)
        backtrack(root, targetSum)
        return res