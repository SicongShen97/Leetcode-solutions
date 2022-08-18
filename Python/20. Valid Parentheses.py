class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 == 1:
            return False
        st = []
        map_ = {'{': '}', '[': ']', '(':')'}
        for a in s:
            if a in ['{', '[', '(']:
                st.append(map_[a])
            elif len(st) == 0 or st[-1] != a:
                return False
            else:
                st.pop(-1)
        return len(st) == 0