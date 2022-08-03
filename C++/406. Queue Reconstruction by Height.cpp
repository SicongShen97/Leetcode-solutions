/*
贪心算法：
优先按身高从高到低排，若身高相同，k低的排前面，然后从前往后进行插入
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