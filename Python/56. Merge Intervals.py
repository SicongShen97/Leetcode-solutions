'''
贪心：按左区间从小到大排列， 从前往后遍历，左区间小于最大右区间时合并，否则开始新区间
'''
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        left = intervals[0][0]
        right = intervals[0][1]
        res = []
        for i in intervals:
            if i[0] > right:
                res.append([left, right])
                left = i[0]
                right = i[1]
            else:
                right = max(right, i[1])
        res.append([left, right])
        return res  