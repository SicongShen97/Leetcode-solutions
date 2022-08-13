'''
1.递归
2.回溯
'''


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# class Solution:
#     def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
#         if not root:
#             return False
#         sum_ = 0
#         def traversal(root, targetSum):
#             nonlocal sum_
#             sum_ += root.val
#             if not root.left and not root.right and sum_ == targetSum:
#                 return True
#             if root.left and traversal(root.left, targetSum):
#                 return True
#             if root.right and traversal(root.right, targetSum):
#                 return True
#             sum_ -= root.val
#             return False
#         return traversal(root, targetSum)

class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False
        st = [(root, root.val)]
        while st:
            cur = st.pop(-1)
            if not cur[0].left and not cur[0].right and cur[1] == targetSum:
                return True
            if cur[0].right:
                st.append((cur[0].right, cur[0].right.val + cur[1]))
            if cur[0].left:
                st.append((cur[0].left, cur[0].left.val + cur[1]))
        return False
