'''
动态规划：
1. dp及其含义：dp[i][j]表示以nums1[i-1], nums2[j-1]结尾的最长重复子串
2. 递推公式：
if (nums1[i-1] == nums2[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}
3. 初始化：dp[0][j] = 0, dp[i][0] = 0
4. 遍历顺序：先nums1再nums2, 从前往后
'''
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        m, n = len(nums1), len(nums2)
        dp = [[0 for _ in range(n+1)] for _ in range(m+1)]
        res = 0
        for i in range(1, m+1):
            for j in range(1, n+1):
                if nums1[i-1] == nums2[j-1]:
                    dp[i][j] = dp[i-1][j-1] + 1
                    res = max(res, dp[i][j])
        return res