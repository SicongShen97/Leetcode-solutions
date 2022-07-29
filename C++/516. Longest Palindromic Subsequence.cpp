/*
��̬�滮��
1. dp���京�壺dp[i][j]��ʾ[i,j]������ַ�����������Ӵ�
2. ���ƹ�ʽ��
if (s[i] == s[j]){
    if (j-i <= 1){
        dp[i][j] = j-i+1;
    }else{
        dp[i][j] = dp[i+1][j-1] + 2;
    }
}else{
    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
}
3. ��ʼ����dp[i][j] = 0;
4.����˳�򣺴��µ��ϣ�������
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = j - i + 1;
                    }
                    else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }
                else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};