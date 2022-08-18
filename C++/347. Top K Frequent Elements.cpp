// 用优先队列， 小根堆， 超过k就pop
class Solution {
public:
    class myCompare {
    public:
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int a : nums) map[a]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, myCompare> pri_que;
        for (auto m : map) {
            pri_que.push(m);
            if (pri_que.size() > k) pri_que.pop();
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }
        return res;

    }
};