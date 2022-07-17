/*
��̬�滮��01����
ÿ���ַ���Ϊһ��Ʒ��costΪ"0","1"���Եĺ�����valusΪ1
1.ȷ��dp�����壺dp[i][j]��ʾ"0","1"��������ֱ�Ϊi��j������������ַ���������
2.ȷ�����ƹ�ϵ: dp[i][j] = max(dp[i][j], dp[i-numZero][j-numOne]+1)
3.��ʼ����dp[i][j] = 0
4.����˳���ȱ����ַ������ٱ��������������Ӵ�С
*/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (string str : strs) {
            int numZero = 0;
            int numOne = 0;
            for (char c : str) {
                if (c == '0') numZero += 1;
                else numOne += 1;
            }
            for (int i = m; i >= numZero; i--) {
                for (int j = n; j >= numOne; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - numZero][j - numOne] + 1);
                }
            }
        }
        return dp[m][n];
    }
};