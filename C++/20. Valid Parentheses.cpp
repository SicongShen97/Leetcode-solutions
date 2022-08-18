class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if (s.size() % 2 == 1) return false;
        for (char a : s) {
            if (a == '(') st.push(')');
            else if (a == '[') st.push(']');
            else if (a == '{') st.push('}');
            else if (st.empty() || st.top() != a) return false;
            else st.pop();
        }
        return st.empty();
    }
};