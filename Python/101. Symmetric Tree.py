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
#     def isSymmetric(self, root: Optional[TreeNode]) -> bool:
#         def compare(left, right):
#             if not left and not right:
#                 return True
#             if not left or not right:
#                 return False
#             if left.val != right.val:
#                 return False
#             outside = compare(left.left, right.right)
#             inside = compare(left.right, right.left)
#             return outside and inside
#         return compare(root.left, root.right)

class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        vec = [root.left, root.right]
        while vec:
            left = vec.pop(0)
            right = vec.pop(0)
            if not left and not right:
                continue
            if not left or not right or (left.val != right.val):
                return False
            vec.append(left.left)
            vec.append(right.right)
            vec.append(left.right)
            vec.append(right.left)
        return True