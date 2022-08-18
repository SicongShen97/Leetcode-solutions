class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        st = []
        for a in tokens:
            if a == '+' or a == '-' or a == '*' or a == '/':
                num2 = st.pop(-1)
                num1 = st.pop(-1)
                if a == '+': st.append(num1 + num2)
                if a == '-': st.append(num1 - num2)
                if a == '*': st.append(num1 * num2)
                if a == '/': st.append(int(num1 / num2))
            else:
                st.append(int(a))
        return st[-1]