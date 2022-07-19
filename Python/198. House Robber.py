'''
动态规划：
1.确定dp及其含义：dp[i]表示下标i以内(包括i)的房屋最多能偷的钱
2.确定递推公式：dp[i] = max(dp[i-1], dp[i-2]+nums[i])
3.初始化：dp[0] = nums[0], dp[1] = max(nums[0], nums[1])
4.遍历顺序：从前往后
'''
class Solution:
    def rob(self, nums: List[int]) -> int:
        if len(nums) == 0: return 0
        if len(nums) == 1: return nums[0]
        dp1 = nums[0]
        dp2 = max(nums[0], nums[1])
        for i in range(2, len(nums)):
            temp = max(dp2, dp1+nums[i])
            dp1 = dp2
            dp2 = temp
        return dp2