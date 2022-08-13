'''
递归
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def traversal(inorder, postorder, in_begin, in_end, post_begin, post_end):
            if post_begin == post_end:
                return None
            mid = postorder[post_begin:post_end][-1]
            mid_index = 0
            for i in range(in_begin, in_end):
                if inorder[i] == mid:
                    mid_index = i
                    break
            node = TreeNode(mid)
            left_len = mid_index - in_begin
            right_len = in_end - mid_index - 1
            node.left = traversal(inorder, postorder, in_begin, mid_index, post_begin, post_begin + left_len)
            node.right = traversal(inorder, postorder, mid_index + 1, in_end, post_begin + left_len, post_end - 1)
            return node
        return traversal(inorder, postorder, 0, len(inorder), 0, len(postorder))