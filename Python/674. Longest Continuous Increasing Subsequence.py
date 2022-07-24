'''
动态规划：
1.dp及其含义：dp[i]表示i之前（包括i）且以nums[i]为结尾的最长连续递增子序列的长度
2.递推公式：
if (nums[i] > nums[i-1]){
    dp[i] = dp[i-1] + 1;
}
3.初始化：dp[i] = 1;
4.遍历顺序：从前往后
'''
class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1: return 1
        dp = [1 for _ in range(n)]
        res = 1
        for i in range(1, n):
            if (nums[i] > nums[i-1]):
                dp[i] = dp[i-1] + 1
            res = max(res, dp[i])
        return res