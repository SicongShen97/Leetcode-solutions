/*
回溯：横向遍历end，纵向递归start
*/
class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    bool isPalindrome(const string& s, int start, int end) {
        if (start == end) return true;
        while (start < end) {
            if (s[start] == s[end]) {
                start++;
                end--;
            }
            else {
                return false;
            }
        }
        return true;
    }

    void backtrack(string s, int start) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1);
                path.pop_back();
            }
            else {
                continue;
            }
        }
    }
    vector<vector<string>> partition(string s) {
        path.clear();
        res.clear();
        backtrack(s, 0);
        return res;
    }
};