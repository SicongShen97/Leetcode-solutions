# 贪心算法：把胃口大的孩子先用最大尺寸的饼干喂
class Solution:
    def findContentChildren(self, g: List[int], s: List[int]) -> int:
        g.sort()
        s.sort()
        index = len(s) - 1
        res = 0
        for i in range(len(g)-1, -1, -1):
            if index >= 0 and g[i] <= s[index]:
                index -= 1
                res += 1
        return res