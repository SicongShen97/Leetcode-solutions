'''
1.递归
2.迭代
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# class Solution:
#     def findMode(self, root: Optional[TreeNode]) -> List[int]:
#         res = []
#         pre = None
#         cur_count = 1
#         max_count = 1
#         def traversal(node):
#             nonlocal pre, cur_count, max_count, res
#             if not node:
#                 return
#             traversal(node.left)
#             if pre:
#                 if pre.val == node.val:
#                     cur_count += 1
#                 else:
#                     cur_count = 1
#             pre = node
#             if cur_count == max_count:
#                 res.append(node.val)
#             elif cur_count > max_count:
#                 max_count = cur_count
#                 res = [node.val]
#             traversal(node.right)
#         traversal(root)
#         return res

class Solution:
    def findMode(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        pre = None
        cur_count = 1
        max_count = 1
        st = [root]
        while st:
            cur = st.pop(-1)
            if cur:
                if cur.right: st.append(cur.right)
                st.append(cur)
                st.append(None)
                if cur.left: st.append(cur.left)
            else:
                cur = st.pop(-1)
                if pre:
                    if pre.val == cur.val: cur_count += 1
                    else: cur_count = 1
                pre = cur
                if cur_count == max_count: res.append(cur.val)
                elif cur_count > max_count:
                    max_count = cur_count
                    res = [cur.val]
        return res