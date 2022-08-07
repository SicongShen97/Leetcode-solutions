'''
回溯：横向遍历每个candidate，纵向递归candidates
'''
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        path = []
        res = []
        def backtrack(candidates, target, start):
            if sum(path) == target:
                res.append(path[:])
                return
            elif sum(path) > target:
                return
            for i in range(start, len(candidates)):
                path.append(candidates[i])
                backtrack(candidates, target, i)
                path.pop()
        backtrack(candidates, target, 0)
        return res