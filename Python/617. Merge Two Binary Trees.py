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
#     def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
#         if not root1 and not root2:
#             return None
#         elif not root1:
#             return root2
#         elif not root2:
#             return root1
#         node = TreeNode(root1.val + root2.val)
#         node.left = self.mergeTrees(root1.left, root2.left)
#         node.right = self.mergeTrees(root1.right, root2.right)
#         return node

class Solution:
    def mergeTrees(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root1 and not root2:
            return None
        if not root1:
            return root2
        if not root2:
            return root1
        que = [root1, root2]
        while que:
            node1 = que.pop(0)
            node2 = que.pop(0)
            node1.val += node2.val
            if node1.left and node2.left:
                que.append(node1.left)
                que.append(node2.left)
            if node1.right and node2.right:
                que.append(node1.right)
                que.append(node2.right)
            if not node1.left and node2.left:
                node1.left = node2.left
            if not node1.right and node2.right:
                node1.right = node2.right
        return root1