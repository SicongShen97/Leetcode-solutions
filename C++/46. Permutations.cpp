/*
回溯：横向遍历数字，纵向遍历不重复的数字
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<bool>& used) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (!used[nums[i] + 10]) {
                used[nums[i] + 10] = true;
                path.push_back(nums[i]);
                backtrack(nums, used);
                path.pop_back();
                used[nums[i] + 10] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(21, false);
        backtrack(nums, used);
        return res;
    }
};