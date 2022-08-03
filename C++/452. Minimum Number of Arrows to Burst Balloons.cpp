/*
贪心算法：
先将左区间从小到大排序，然后从左到右遍历，当遇到左区间大于最小右区间，则需要额外加箭
*/
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[0] < b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int minRight = INT_MAX;
        int res = 1;
        for (auto p : points) {
            if (p[0] <= minRight) {
                minRight = min(minRight, p[1]);
            }
            else {
                res++;
                minRight = p[1];
            }
        }
        return res;
    }
};