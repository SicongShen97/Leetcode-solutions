'''
回溯：横向遍历不重复数字，纵向递归数字
'''
class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        path = []
        res = []
        def backtrack(nums, start):
            nonlocal path
            nonlocal res
            res.append(path[:])
            if start == len(nums):
                return
            prev = 0
            for i in range(start, len(nums)):
                if i == start:
                    prev = nums[i]
                elif nums[i] == prev:
                    continue
                prev = nums[i]
                path.append(nums[i])
                backtrack(nums, i+1)
                path.pop()
        nums.sort()
        backtrack(nums, 0)
        return res