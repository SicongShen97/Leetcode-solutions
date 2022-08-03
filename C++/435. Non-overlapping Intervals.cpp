/*
̰���㷨����intervals���������С�������У���һ��ʱ�����������ģ��ٴ�ǰ�����������¼��ǰ�����䣬����������ڵ��ڵ�ǰ������ʱ��˵�����ص�
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