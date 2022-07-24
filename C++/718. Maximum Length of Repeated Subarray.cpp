/*
��̬�滮��
1. dp���京�壺dp[i][j]��ʾ��nums1[i-1], nums2[j-1]��β����ظ��Ӵ�
2. ���ƹ�ʽ��
if (nums1[i-1] == nums2[j-1]){
    dp[i][j] = dp[i-1][j-1] + 1;
}
3. ��ʼ����dp[0][j] = 0, dp[i][0] = 0
4. ����˳����nums1��nums2, ��ǰ����
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                res = max(res, dp[i][j]);
            }
        }
        return res;
    }
};