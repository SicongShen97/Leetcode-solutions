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
#     def maxDepth(self, root: Optional[TreeNode]) -> int:
#         if not root:
#             return 0
#         ldepth = self.maxDepth(root.left)
#         rdepth = self.maxDepth(root.right)
#         return 1 + max(ldepth, rdepth)

class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        depth = 0
        if not root:
            return depth
        que = [root]
        while que:
            depth += 1
            size = len(que)
            for _ in range(size):
                cur = que.pop(0)
                if cur.left: que.append(cur.left)
                if cur.right: que.append(cur.right)
        return depth
