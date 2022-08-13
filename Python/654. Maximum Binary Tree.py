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
    def constructMaximumBinaryTree(self, nums: List[int]) -> Optional[TreeNode]:
        def traversal(nums, begin, end):
            if begin >= end:
                return None
            max_ = nums[begin]
            max_index = begin
            for i in range(begin, end):
                if nums[i] > max_:
                    max_ = nums[i]
                    max_index = i
            node = TreeNode(max_)
            node.left = traversal(nums, begin, max_index)
            node.right = traversal(nums, max_index+1, end)
            return node
        return traversal(nums, 0, len(nums))