'''
回溯：横向遍历end，纵向递归start
'''


class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []
        self.numPoint = 0

        def isValid(s, start, end):
            if start > end: return False
            if s[start] == '0' and start < end: return False
            temp = s[start:end + 1]
            if len(temp) > 3: return False
            if int(temp) >= 0 and int(temp) <= 255: return True
            return False

        def backtrack(s, start):
            if self.numPoint == 3 and isValid(s, start, len(s) - 1):
                res.append(s[:])
                return
            if self.numPoint > 3:
                return
            for end in range(start, len(s)):
                if isValid(s, start, end):
                    s = s[:end + 1] + '.' + s[end + 1:]
                    self.numPoint += 1
                    backtrack(s, end + 2)
                    self.numPoint -= 1
                    s = s[:end + 1] + s[end + 2:]
                else:
                    return

        backtrack(s, 0)
        return res
