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
#     def countNodes(self, root: Optional[TreeNode]) -> int:
#         if not root:
#             return 0
#         left = self.countNodes(root.left)
#         right = self.countNodes(root.right)
#         return 1 + left + right

class Solution:
    def countNodes(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        que = [root]
        res = 0
        while que:
            size = len(que)
            for _ in range(size):
                cur = que.pop(0)
                res += 1
                if cur.left:
                    que.append(cur.left)
                if cur.right:
                    que.append(cur.right)
        return res