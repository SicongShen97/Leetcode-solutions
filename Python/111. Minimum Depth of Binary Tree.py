'''
1.递归
2.迭代
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        if not root.left and not root.right:
            return 1
        elif not root.left:
            return 1 + self.minDepth(root.right)
        elif not root.right:
            return 1 + self.minDepth(root.left)
        else:
            return 1 + min(self.minDepth(root.left), self.minDepth(root.right))

# class Solution:
#     def minDepth(self, root: Optional[TreeNode]) -> int:
#         res = 0
#         que = []
#         if root:
#             que.append(root)
#         while que:
#             res += 1
#             size = len(que)
#             for i in range(size):
#                 cur = que.pop(0)
#                 if cur.left:
#                     que.append(cur.left)
#                 if cur.right:
#                     que.append(cur.right)
#                 if not cur.left and not cur.right:
#                     return res
#         return res