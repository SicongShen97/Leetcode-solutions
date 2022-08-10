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
#     def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
#         if not p and not q:
#             return True
#         if not p or not q or (p.val != q.val):
#             return False
#         left = self.isSameTree(p.left, q.left)
#         right = self.isSameTree(p.right, q.right)
#         return left and right

class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        que = [p, q]
        while que:
            left = que.pop(0)
            right = que.pop(0)
            if (not left and not right):
                continue
            if (not left or not right or left.val != right.val):
                return False
            que.append(left.left)
            que.append(right.left)
            que.append(left.right)
            que.append(right.right)
        return True


