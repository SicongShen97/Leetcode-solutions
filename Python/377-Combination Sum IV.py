'''
动态规划：完全背包
1.确定dp及其含义：dp[i]表示容量刚好为i的所有组合情况
2.递推公式：dp[i] += dp[i - coins[i]]
3.初始化：dp[0]=1, 其余为0
4.遍历顺序：若为组合问题，先物品，再容量从小到大；若为排列问题，先容量从小到大，再物品
本题为排列问题
'''
class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = [0]*(target + 1)
        dp[0] = 1
        for i in range(1, target+1):
            for j in range(len(nums)):
                if nums[j]<=i:
                    dp[i] += dp[i - nums[j]]
        return dp[-1]