'''
横向遍历不重复数字，纵向递归不重复数字
'''
class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        path = []
        res = []
        used = [False]*len(nums)
        def backtrack(nums, used):
            if len(path) == len(nums):
                res.append(path[:])
                return
            prev = -11
            for i in range(len(nums)):
                if not used[i]:
                    if prev == -11 or prev != nums[i]:
                        prev = nums[i]
                        path.append(nums[i])
                        used[i] = True
                        backtrack(nums, used)
                        used[i] = False
                        path.pop()
        nums.sort()
        backtrack(nums, used)
        return res;