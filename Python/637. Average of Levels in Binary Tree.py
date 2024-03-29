'''
层序遍历
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        from collections import deque
        que = deque([root])
        res = []
        while que:
            size = len(que)
            sum_ = 0
            for _ in range(size):
                cur = que.popleft()
                sum_ += cur.val
                if cur.left:
                    que.append(cur.left)
                if cur.right:
                    que.append(cur.right)
            res.append(sum_ / size)
        return res