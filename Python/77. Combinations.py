'''
回溯：横向从i遍历到n，纵向深度为k
'''
class Solution:
    path = []
    res = []
    def backtracking(self, n, k, start):
        if len(self.path) == k:
            self.res.append(self.path[:])
            return
        for i in range(start, n-k+2+len(self.path)):
            self.path.append(i)
            self.backtracking(n, k, i+1)
            self.path.pop()

    def combine(self, n: int, k: int) -> List[List[int]]:
        self.path = []
        self.res = []
        self.backtracking(n, k, 1)
        return self.res