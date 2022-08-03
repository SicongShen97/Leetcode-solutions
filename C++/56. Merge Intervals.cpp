/*
̰�ģ����������С�������У� ��ǰ���������������С�����������ʱ�ϲ�������ʼ������
*/
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        int left = intervals[0][0];
        int right = intervals[0][1];
        for (auto i : intervals) {
            if (i[0] > right) {
                res.push_back(vector<int>{left, right});
                left = i[0];
                right = i[1];
            }
            else {
                right = max(right, i[1]);
            }
        }
        res.push_back(vector<int>{left, right});
        return res;
    }
};