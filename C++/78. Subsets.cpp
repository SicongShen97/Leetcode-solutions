/*
回溯：横向便利数字，纵向遍历取出该数字后的集合
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start) {
        res.push_back(path);
        if (start == nums.size()) return;
        for (int i = start; i < nums.size(); i++) {
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        path.clear();
        res.clear();
        backtrack(nums, 0);
        return res;
    }
};