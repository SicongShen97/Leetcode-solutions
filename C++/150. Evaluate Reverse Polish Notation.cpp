class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (auto a : tokens) {
            if (a == "+" || a == "-" || a == "*" || a == "/") {
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                if (a == "+") st.push(num1 + num2);
                if (a == "-") st.push(num1 - num2);
                if (a == "*") st.push(num1 * num2);
                if (a == "/") st.push(num1 / num2);
            }
            else {
                st.push(stoi(a));
            }
        }
        return st.top();
    }
};