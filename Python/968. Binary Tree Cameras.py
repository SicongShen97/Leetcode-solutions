'''
贪心：后序遍历，优先父节点装摄像头，回溯返回值：0：该节点无覆盖，1：该节点有摄像头，2：该节点有覆盖
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    res = 0
    def traversal(self, node):
        if node is None:
            return 2
        left = self.traversal(node.left)
        right = self.traversal(node.right)
        if (left == 0 or right == 0):
            self.res += 1
            return 1
        elif (left == 1 or right == 1):
            return 2
        else:
            return 0
    def minCameraCover(self, root: Optional[TreeNode]) -> int:
        if self.traversal(root) == 0:
            self.res += 1
        return self.res