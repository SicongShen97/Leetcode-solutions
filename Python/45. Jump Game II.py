'''
贪心：每次记录当前的覆盖范围和下一次的覆盖范围，当到达当前覆盖范围时，步数加1
'''
class Solution:
    def jump(self, nums: List[int]) -> int:
        cur = 0
        next = 0
        res = 0
        for i in range(len(nums) - 1):
            next = max(next, i + nums[i])
            if i == cur:
                res += 1
                cur = next
        return res