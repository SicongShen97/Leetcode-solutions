/*
��̬�滮��
1. dp���京�壺dp[i][j]��ʾ��word1[i-1]Ϊ�׵��ַ�������word2[j-1]Ϊ�׵��ַ�������С�༭����
2. ���ƹ�ʽ��
if (word1[i-1] == word2[j-1]){
    dp[i][j] = dp[i-1][j-1];
}else{
    //ɾ
    int del = dp[i-1][j] + 1;
    //��,�൱��word2ɾ
    int add = dp[i][j-1] + 1;
    //��
    int rep = dp[i-1][j-1] + 1;
    //ȡmin
    dp[i][j] = min({del, add, rep});
}
3. ��ʼ����dp[i][0] = i, dp[0][j] = j
4. ����˳����word1��word2����ǰ����
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
            dp[0][j] = j;
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    int add = dp[i][j - 1] + 1;
                    int del = dp[i - 1][j] + 1;
                    int rep = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min({ add, del, rep });
                }
            }
        }
        return dp[m][n];
    }
};