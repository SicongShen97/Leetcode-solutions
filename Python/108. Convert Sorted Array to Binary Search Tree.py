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
#     def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
#         def createBST(nums, left, right):
#             if left >= right:
#                 return None
#             mid = (left + right) // 2
#             node = TreeNode(nums[mid])
#             node.left = createBST(nums, left, mid)
#             node.right = createBST(nums, mid+1, right)
#             return node
#         return createBST(nums, 0, len(nums))

class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        root = TreeNode(0)
        que = [root]
        leftQue = [0]
        rightQue = [len(nums) - 1]
        while que:
            node = que.pop(0)
            left = leftQue.pop(0)
            right = rightQue.pop(0)
            mid = (left + right) // 2
            node.val = nums[mid]
            if left < mid:
                node.left = TreeNode(0)
                que.append(node.left)
                leftQue.append(left)
                rightQue.append(mid-1)
            if mid < right:
                node.right = TreeNode(0)
                que.append(node.right)
                leftQue.append(mid+1)
                rightQue.append(right)
        return root