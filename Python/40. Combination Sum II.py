'''
回溯：横向遍历每个candidate，纵向递归candidates
'''
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        path = []
        res = []
        candidates.sort()
        def backtrack(candidates, target, start):
            if (sum(path) == target):
                res.append(path[:])
                return
            elif (sum(path) > target):
                return
            prev = 0
            for i in range(start, len(candidates)):
                if i == start:
                    prev = candidates[i]
                elif prev == candidates[i]:
                    continue
                prev = candidates[i]
                path.append(candidates[i])
                backtrack(candidates, target, i+1)
                path.pop()
        backtrack(candidates, target, 0)
        return res