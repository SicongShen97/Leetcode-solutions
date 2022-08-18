//用单调队列来从大到小存放滑动窗口的值 
class Solution {
public:
    class MyQueue {
    public:
        deque<int> que;
        void push(int val) {
            while (!que.empty() && que.back() < val) que.pop_back();
            que.push_back(val);
        }

        void pop(int val) {
            if (!que.empty() && que.front() == val) que.pop_front();
        }

        int front() {
            return que.front();
        }
        bool empty() {
            return que.empty();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        for (int i = 0; i < k; i++) {
            que.push(nums[i]);
        }
        vector<int> vec;
        vec.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            vec.push_back(que.front());
        }
        return vec;
    }
};