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
#     def isValidBST(self, root: Optional[TreeNode]) -> bool:
#         pre = None
#         def __isValidBST(root):
#             nonlocal pre
#             if not root:
#                 return True
#             left = __isValidBST(root.left)
#             if pre and pre.val >= root.val:
#                 return False
#             pre = root
#             right = __isValidBST(root.right)
#             return left and right
#         return __isValidBST(root)

class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        pre = None
        st = [root]
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
                if pre and pre.val >= cur.val:
                    return False
                pre = cur
        return True