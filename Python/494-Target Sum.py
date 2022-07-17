'''
动态规划
1.确定dp及含义：dp[i]表示容量为i的背包刚好装满的所有可能情况
2.递推公式：dp[i] += dp[i-nums[j]](nums[j]表示新增一个可选物品nums[j])
3.初始化：无任何物可选时，dp[0] = 1, 其他均为0
4.遍历顺序：外层物品，内层容量从大到小
'''


class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        res = sum(nums)
        if (res + target) % 2 != 0:
            return 0
        if (abs(target) > res):
            return 0

        pos = (res + target) // 2
        dp = [0] * (pos + 1)
        dp[0] = 1

        for j in range(len(nums)):
            for i in range(pos, nums[j] - 1, -1):
                dp[i] += dp[i - nums[j]]
        return dp[pos]