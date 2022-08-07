/*
回溯：横向遍历end，纵向递归start
*/
class Solution {
public:
    int numPoint = 0;
    vector<string> res;
    bool isValid(const string& s, int start, int end) {
        if (start > end) return false;
        if (s[start] == '0' && end > start) return false;
        string temp = s.substr(start, end - start + 1);
        if (temp.size() > 3) return false;
        if (stoi(temp) >= 0 && stoi(temp) <= 255) return true;
        return false;
    }
    void backtrack(string& s, int start) {
        if (numPoint == 3) {
            if (isValid(s, start, s.size() - 1)) {
                res.push_back(s);
            }
            return;
        }
        for (int end = start; end < start + 3 && end < s.size(); end++) {
            if (isValid(s, start, end)) {
                s.insert(s.begin() + end + 1, '.');
                numPoint += 1;
                backtrack(s, end + 2);
                numPoint -= 1;
                s.erase(s.begin() + end + 1);
            }
            else {
                return;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        numPoint = 0;
        res.clear();
        backtrack(s, 0);
        return res;
    }
};