/*
贪心算法：将intervals按右区间从小到大排列，当一样时，先左区间大的，再从前往后遍历，记录当前右区间，当左区间大于等于当前右区间时，说明无重叠
*/
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[1] == b[1]) return a[0] > b[0];
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int del = 0;
        int curRight = -INT_MAX;
        for (auto i : intervals) {
            if (i[0] >= curRight) {
                curRight = i[1];
            }
            else {
                del++;
            }
        }
        return del;
    }
};