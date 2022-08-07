'''
回溯：横向遍历数字，纵向遍历不重复的数字
'''
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        path = []
        res = []
        used = [False]*len(nums)
        def backtrack(nums, used):
            if len(path) == len(nums):
                res.append(path[:])
                return
            for i in range(len(nums)):
                if not used[i]:
                    used[i] = True
                    path.append(nums[i])
                    backtrack(nums, used)
                    path.pop()
                    used[i] = False
        backtrack(nums, used)
        return res