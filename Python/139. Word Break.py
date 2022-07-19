'''
动态规划：完全背包
1.确定dp及其含义：dp[i]表示长度为i的字符串可被拆分
2.递推关系：if(dp[j]=true 且 区间[j,i]出现在字典里)：dp[i]=true
3.初始化：dp[0]=true, 其余false
4.遍历顺序：完全背包：容量从小到大，先容量再物品
'''
class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        dp = [False]*(len(s)+1)
        dp[0] = True
        for i in range(1, len(s)+1):
            for j in range(len(wordDict)):
                word = wordDict[j]
                n = len(word)
                if i>=n and dp[i-n]==True and s[i-n:i]==word:
                    dp[i] = True
        return dp[-1]