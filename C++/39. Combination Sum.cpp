/*
回溯：横向遍历每个candidate，纵向递归candidates
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    int sum = 0;
    void backtrack(vector<int>& candidates, int target, int start) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        else if (sum > target) {
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, target, i);
            sum -= candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        sum = 0;
        backtrack(candidates, target, 0);
        return res;
    }
};