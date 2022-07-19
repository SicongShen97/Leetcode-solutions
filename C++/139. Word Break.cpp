/*
动态规划：完全背包
1.确定dp及其含义：dp[i]表示长度为i的字符串可被拆分
2.递推关系：if(dp[j]=true 且 区间[j,i]出现在字典里)：dp[i]=true
3.初始化：dp[0]=true, 其余false
4.遍历顺序：完全背包：容量从小到大，先容量再物品
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