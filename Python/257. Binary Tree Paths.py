'''
回溯
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def binaryTreePaths(self, root: Optional[TreeNode]) -> List[str]:
        path = []
        res = []
        def backtrack(node):
            path.append(str(node.val))
            if not node.left and not node.right:
                res.append('->'.join(path))
            if node.left:
                backtrack(node.left)
            if node.right:
                backtrack(node.right)
            path.pop(-1)
        backtrack(root)
        return res