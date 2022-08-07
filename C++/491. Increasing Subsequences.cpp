/*
回溯：横向遍历不重复的数字，纵向遍历数字
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start) {
        if (path.size() >= 2) {
            res.push_back(path);
        }

        if (nums.size() - start + path.size() < 2) return;
        vector<bool> used(201, false);
        for (int i = start; i < nums.size(); i++) {
            if (!used[nums[i] + 100]) {
                used[nums[i] + 100] = true;
                if (path.size() == 0 || path[path.size() - 1] <= nums[i]) {
                    path.push_back(nums[i]);
                    backtrack(nums, i + 1);
                    path.pop_back();
                }
                else {
                    continue;
                }
            }
            else {
                continue;
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        path.clear();
        res.clear();
        backtrack(nums, 0);
        return res;
    }
};