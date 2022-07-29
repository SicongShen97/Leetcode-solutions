/*
��̬�滮��
1. dp���京�壺dp[i][j]��ʾ�ַ���������[i,j]�����ַ����Ƿ�Ϊ����
2. ���ƹ�ʽ��
if (s[i] == s[j]){
    if(j-i <= 1){
        dp[i][j] = true;
        result++;
    }
    else if(dp[i+1][j-1]){
        dp[i][j] = true;
        result++;
    }
}
3. ��ʼ����dp[i][j] = false
4. ����˳�򣺴��µ��ϣ���������
*/
class Solution {
public:
    int countSubstrings(string s) {
        if (s.size() == 1) return 1;
        int result = 0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                        result++;
                    }
                    else if (dp[i + 1][j - 1]) {
                        dp[i][j] = true;
                        result++;
                    }
                }
            }
        }
        return result;
    }
};