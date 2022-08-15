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
#     def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
#         sum_ = 0
#         def traversal(root):
#             nonlocal sum_
#             if not root:
#                 return
#             traversal(root.right)
#             root.val += sum_
#             sum_ = root.val
#             traversal(root.left)
#         traversal(root)
#         return root

class Solution:
    def convertBST(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        st = [root]
        sum_ = 0
        while st:
            node = st.pop(-1)
            if node:
                if node.left: st.append(node.left)
                st.append(node)
                st.append(None)
                if node.right: st.append(node.right)
            else:
                node = st.pop(-1)
                node.val += sum_
                sum_ = node.val
        return root