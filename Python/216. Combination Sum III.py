'''
回溯：横向遍历1至9，纵向深度为k
'''
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        path = []
        res = []
        def backtrack(k, n, start):
            if len(path) == k and sum(path) == n:
                res.append(path[:])
                return
            if sum(path) > n or len(path) > k:
                return
            for i in range(start, 10):
                path.append(i)
                backtrack(k, n, i+1)
                path.pop()
        backtrack(k, n, 1)
        return res