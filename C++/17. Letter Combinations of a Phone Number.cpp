/*
回溯：横向遍历每个数字对应的字母，纵向递归数字
*/
class Solution {
public:
    const string letterMap[10] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"
    };
    string path = "";
    vector<string> res;
    void backtrack(string digits, int start) {
        if (start == digits.size()) {
            res.push_back(path);
            return;
        }
        int index = digits[start] - '0';
        string s = letterMap[index];
        for (auto w : s) {
            path.push_back(w);
            backtrack(digits, start + 1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        path.clear();
        res.clear();
        if (digits.size() == 0) return res;
        backtrack(digits, 0);
        return res;
    }
};