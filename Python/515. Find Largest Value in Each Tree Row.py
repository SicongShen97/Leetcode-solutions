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
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if not root:
            return res
        que = [root]
        while que:
            size = len(que)
            max_ = -float('inf')
            for _ in range(size):
                cur = que.pop(0)
                max_ = max(max_, cur.val)
                if cur.left:
                    que.append(cur.left)
                if cur.right:
                    que.append(cur.right)
            res.append(max_)
        return res