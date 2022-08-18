class Solution {
public:
    string removeDuplicates(string s) {
        string st;
        for (char a : s) {
            if (st.empty()) st.push_back(a);
            else if (st.back() == a) st.pop_back();
            else st.push_back(a);
        }
        return st;
    }
};