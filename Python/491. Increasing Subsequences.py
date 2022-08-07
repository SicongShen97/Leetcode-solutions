'''
回溯：横向遍历不重复的数字，纵向遍历数字
'''
class Solution:
    def findSubsequences(self, nums: List[int]) -> List[List[int]]:
        path = []
        res = []
        def backtrack(nums, start):
            nonlocal path, res
            if len(path) >= 2:
                res.append(path[:])
            used = [False]*201
            for i in range(start, len(nums)):
                if not used[nums[i] + 100]:
                    used[nums[i] + 100] = True
                    if len(path) == 0 or path[-1] <= nums[i]:
                        path.append(nums[i])
                        backtrack(nums, i+1)
                        path.pop()
                    else:
                        continue
        backtrack(nums, 0)
        return res