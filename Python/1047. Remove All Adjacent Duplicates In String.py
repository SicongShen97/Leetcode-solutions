class Solution:
    def removeDuplicates(self, s: str) -> str:
        st = []
        for a in s:
            if not st:
                st.append(a)
            elif st[-1] == a:
                st.pop(-1)
            else:
                st.append(a)
        return ''.join(st)