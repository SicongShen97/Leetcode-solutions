'''
1.递归
2.层序遍历
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# class Solution:
#     def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
#         if not root:
#             return root
#         root.left, root.right = root.right, root.left
#         self.invertTree(root.left)
#         self.invertTree(root.right)
#         return root

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        que = [root]
        while que:
            size = len(que)
            for i in range(size):
                cur = que.pop(0)
                cur.left, cur.right = cur.right, cur.left
                if cur.left:
                    que.append(cur.left)
                if cur.right:
                    que.append(cur.right)
        return root