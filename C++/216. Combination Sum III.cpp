/*
回溯：横向遍历1至9，纵向深度为k
*/
class Solution {
public:
    int sum = 0;
    vector<int> path;
    vector<vector<int>> res;
    void backtrack(int k, int n, int start, int sum) {
        if (path.size() == k && sum == n) {
            res.push_back(path);
            return;
        }
        if (sum > n) return;
        for (int i = start; i <= 9 - k + 1 + path.size(); i++) {
            path.push_back(i);
            sum += i;
            backtrack(k, n, i + 1, sum);
            sum -= i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        sum = 0;
        backtrack(k, n, 1, sum);
        return res;
    }
};