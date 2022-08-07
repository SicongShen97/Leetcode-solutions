'''
回溯：横向便利数字，纵向遍历取出该数字后的集合
'''
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        path = []
        res = []
        def backtrack(nums, start):
            nonlocal path, res
            res.append(path[:])
            if start == len(nums):
                return
            for i in range(start, len(nums)):
                path.append(nums[i])
                backtrack(nums, i+1)
                path.pop()
        backtrack(nums, 0)
        return res