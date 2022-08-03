'''
贪心算法：
先将左区间从小到大排序，然后从左到右遍历，当遇到左区间大于最小右区间，则需要额外加箭
'''
class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort(key=lambda x: x[0])
        minRight = float('inf')
        res = 1
        for p in points:
            if p[0]<=minRight:
                minRight = min(minRight, p[1])
            else:
                res += 1
                minRight = p[1]
        return res