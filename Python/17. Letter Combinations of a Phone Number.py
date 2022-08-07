'''
回溯：横向遍历每个数字对应的字母，纵向递归数字
'''
class Solution:
    letterMap = ["", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"]
    path = ""
    res = []
    def backtrack(self, digits, start):
        if start == len(digits):
            self.res.append(self.path)
            return
        index = int(digits[start])
        string = self.letterMap[index]
        for s in string:
            self.path += s
            self.backtrack(digits, start+1)
            self.path = self.path[:-1]
    def letterCombinations(self, digits: str) -> List[str]:
        self.res.clear()
        if not digits:
            return self.res
        self.backtrack(digits, 0)
        return self.res