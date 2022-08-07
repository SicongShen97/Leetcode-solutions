/*
���ݣ�����������ظ����֣�����ݹ�����
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int start) {
        res.push_back(path);
        if (start == nums.size()) {
            return;
        }
        int prev;
        for (int i = start; i < nums.size(); i++) {
            if (i == start) {
                prev = nums[i];
            }
            else if (prev == nums[i]) {
                continue;
            }
            prev = nums[i];
            path.push_back(nums[i]);
            backtrack(nums, i + 1);
            path.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        path.clear();
        res.clear();
        backtrack(nums, 0);
        return res;
    }
};