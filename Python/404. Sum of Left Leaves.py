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
#     def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
#         if not root:
#             return 0
#         midVal = 0
#         if root.left and not root.left.left and not root.left.right:
#             midVal = root.left.val
#         return midVal + self.sumOfLeftLeaves(root.left) + self.sumOfLeftLeaves(root.right)

class Solution:
    def sumOfLeftLeaves(self, root: Optional[TreeNode]) -> int:
        st = [root]
        res = 0
        while st:
            cur = st.pop(-1)
            if cur.left and not cur.left.left and not cur.left.right:
                res += cur.left.val
            if cur.right:
                st.append(cur.right)
            if cur.left:
                st.append(cur.left)
        return res