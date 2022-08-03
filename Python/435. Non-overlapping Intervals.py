'''
贪心算法：将intervals按右区间从小到大排列，当一样时，先左区间大的，再从前往后遍历，记录当前右区间，当左区间大于等于当前右区间时，说明无重叠
'''
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[1], -x[0]))
        nDel = 0
        curRight = -float('inf')
        for i in intervals:
            if i[0] >= curRight:
                curRight = i[1]
            else:
                nDel += 1
        return nDel