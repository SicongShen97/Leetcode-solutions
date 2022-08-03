/*
̰���㷨��
���Ȱ���ߴӸߵ����ţ��������ͬ��k�͵���ǰ�棬Ȼ���ǰ������в���
*/
class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        list<vector<int>> que;
        for (auto p : people) {
            int pos = p[1];
            list<vector<int>>::iterator it = que.begin();
            while (pos > 0) {
                pos--;
                it++;
            }
            que.insert(it, p);
        }
        return vector<vector<int>>(que.begin(), que.end());
    }
};