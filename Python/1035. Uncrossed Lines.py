'''
动态规划：
1. 确定dp及其含义：dp[i][j]表示以nums1[i-1]以及nums2[j-1]为底的最长公共子序列
2. 递推公式：
if (nums1[i-1] == nums2[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}else{
    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
}
3. 初始化：dp[i][0] = 0, dp[0][j] = 0
4.遍历顺序：先nums1, 再nums2
'''
class Solution:
    def maxUncrossedLines(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                if nums1[i-1] == nums2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        return dp[-1][-1]