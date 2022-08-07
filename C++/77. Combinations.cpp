/*
回溯：横向从i遍历到n，纵向深度为k
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    void backtracking(int start, int n, int k) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n - k + 1 + path.size(); i++) {
            path.push_back(i);
            backtracking(i + 1, n, k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(1, n, k);
        return res;
    }
};