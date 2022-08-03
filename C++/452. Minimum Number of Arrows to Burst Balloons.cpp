/*
̰���㷨��
�Ƚ��������С��������Ȼ������ұ����������������������С�����䣬����Ҫ����Ӽ�
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