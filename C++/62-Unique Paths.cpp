/*
��̬�滮
1.ȷ��dp���壺dp[i][j]��ʾ����(i, j)�������в�ͬ·��
2.���ƹ�ʽ��dp[i][j] = dp[i-1][j] + dp[i][j-1]
3.��ʼ����dp[0][:] = 1 dp[:][0] = 1
4.����˳�򣺲����������������
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[0][i] = 1;
        for (int j = 0; j < m; j++) dp[j][0] = 1;
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < n; i++) {
                dp[j][i] = dp[j - 1][i] + dp[j][i - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};