'''
贪心算法：记录每个字符的最远位置，分割点就在其中
'''
class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        hash = [0]*26
        for i in range(len(s)):
            hash[ord(s[i]) - ord('a')] = i
        left = 0
        right = 0
        res = []
        for i in range(len(s)):
            right = max(right, hash[ord(s[i]) - ord('a')])
            if i == right:
                res.append(right - left + 1)
                left = right + 1
        return res