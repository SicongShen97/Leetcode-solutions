/*
��̬�滮����ȫ����
1.ȷ��dp���京�壺dp[i]��ʾ����Ϊi���ַ����ɱ����
2.���ƹ�ϵ��if(dp[j]=true �� ����[j,i]�������ֵ���)��dp[i]=true
3.��ʼ����dp[0]=true, ����false
4.����˳����ȫ������������С��������������Ʒ
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                string word = wordDict[j];
                int len = word.size();
                if (i >= word.size() && dp[i - len] == true && s.substr(i - len, len) == word) {
                    dp[i] = true;
                }
            }
        }
        return dp[s.size()];
    }
};