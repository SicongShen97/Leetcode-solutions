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

# class Solution:
#     def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
#         maxDepth = 0
#         res = 0
#         def traversal(root, depth):
#             nonlocal maxDepth, res
#             if not root.left and not root.right:
#                 if depth > maxDepth:
#                     maxDepth = depth
#                     res = root.val
#                     return
#             if root.left: traversal(root.left, depth + 1)
#             if root.right: traversal(root.right, depth + 1)
#         traversal(root, 1)
#         return res

class Solution:
    def findBottomLeftValue(self, root: Optional[TreeNode]) -> int:
        que = [root]
        res = 0
        while que:
            size = len(que)
            for i in range(size):
                cur = que.pop(0)
                if i == 0:
                    res = cur.val
                if cur.left: que.append(cur.left)
                if cur.right: que.append(cur.right)
        return res
