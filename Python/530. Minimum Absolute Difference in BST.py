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
#     def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
#         res = float('inf')
#         pre = None
#         def traversal(node):
#             nonlocal res, pre
#             if not node:
#                 return
#             if node.left:
#                 traversal(node.left)
#             if pre:
#                 res = min(res, node.val - pre.val)
#             pre = node
#             if node.right:
#                 traversal(node.right)
#         traversal(root)
#         return res

class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        st = [root]
        res = float('inf')
        pre = None
        while st:
            cur = st.pop(-1)
            if cur:
                if cur.right:
                    st.append(cur.right)
                st.append(cur)
                st.append(None)
                if cur.left:
                    st.append(cur.left)
            else:
                cur = st.pop(-1)
                if pre:
                    res = min(res, cur.val - pre.val)
                pre = cur
        return res