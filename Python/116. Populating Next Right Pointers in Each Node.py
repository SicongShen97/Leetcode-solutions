'''
层序遍历
'''
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""


class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        que = [root]
        while que:
            size = len(que)
            pre = None
            for i in range(size):
                cur = que.pop(0)
                if i == 0:
                    pre = cur
                else:
                    pre.next = cur
                    pre = cur
                if cur.left:
                    que.append(cur.left)
                if cur.right:
                    que.append(cur.right)
            pre.next = None
        return root
