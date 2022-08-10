'''
1.递归
2.迭代
'''
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


# class Solution:
#     def maxDepth(self, root: 'Node') -> int:
#         if not root:
#             return 0
#         max_ = 0
#         for child in root.children:
#             max_ = max(max_, self.maxDepth(child))
#         return 1 + max_

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        depth = 0
        if not root:
            return depth
        que = [root]
        while que:
            depth += 1
            size = len(que)
            for _ in range(size):
                cur = que.pop(0)
                for child in cur.children:
                    que.append(child)
        return depth