'''
1.迭代
2.递归
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# class Solution:
#     def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
#         if not root: return root
#         if root.val < low:
#             return self.trimBST(root.right, low, high)
#         elif root.val > high:
#             return self.trimBST(root.left, low, high)
#         else:
#             root.left = self.trimBST(root.left, low, high)
#             root.right = self.trimBST(root.right, low, high)
#         return root

class Solution:
    def trimBST(self, root: Optional[TreeNode], low: int, high: int) -> Optional[TreeNode]:
        if not root: return root
        while root:
            if root.val < low: root = root.right
            elif root.val > high: root = root.left
            else: break
        if not root: return root
        node = root
        while node:
            while node.left and node.left.val < low:
                node.left = node.left.right
            node = node.left
        node = root
        while node:
            while node.right and node.right.val > high:
                node.right = node.right.left
            node = node.right
        return root