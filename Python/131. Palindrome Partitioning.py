'''
回溯：横向遍历end，纵向递归start
'''
class Solution:
    def partition(self, s: str) -> List[List[str]]:
        path = []
        res = []
        def backtrack(s, start):
            if start == len(s):
                res.append(path[:])
                return
            for end in range(start, len(s)):
                temp = s[start:end+1]
                if temp == temp[::-1]:
                    path.append(temp)
                    backtrack(s, end+1)
                    path.pop()
                else:
                    continue
        backtrack(s, 0)
        return res