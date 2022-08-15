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
#     def deleteOneNode(self, node):
#         if not node.left and not node.right:
#             return None
#         elif not node.left:
#             return node.right
#         elif not node.right:
#             return node.left
#         else:
#             temp = node.right
#             while temp.left: temp = temp.left
#             temp.left = node.left
#             return node.right

#     def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
#         if not root:
#             return root
#         if root.val > key:
#             root.left = self.deleteNode(root.left, key)
#         elif root.val < key:
#             root.right = self.deleteNode(root.right, key)
#         else:
#             return self.deleteOneNode(root)
#         return root

class Solution:
    def deleteOneNode(self, node):
        if not node.left and not node.right:
            return None
        elif not node.left:
            return node.right
        elif not node.right:
            return node.left
        else:
            temp = node.right
            while temp.left: temp = temp.left
            temp.left = node.left
            return node.right

    def deleteNode(self, root: Optional[TreeNode], key: int) -> Optional[TreeNode]:
        if not root: return root
        cur = root
        pre = None
        while cur:
            if cur.val == key:
                break
            pre = cur
            if cur.val > key:
                cur = cur.left
            else:
                cur = cur.right
        if not cur: return root
        if not pre: return self.deleteOneNode(root)
        if pre.left and pre.left.val == key: pre.left = self.deleteOneNode(cur)
        if pre.right and pre.right.val == key: pre.right = self.deleteOneNode(cur)
        return root