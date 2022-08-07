/*
横向遍历不重复数字，纵向递归不重复数字
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
        int prev = -11;
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                if (prev == -11 || nums[i] != prev) {
                    prev = nums[i];
                    path.push_back(nums[i]);
                    used[i] = true;
                    backtrack(nums, used);
                    used[i] = false;
                    path.pop_back();
                }
            }

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        path.clear();
        res.clear();
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        backtrack(nums, used);
        return res;
    }
};