# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
'''
动态规划：
1.确定dp及其含义：每一层递归中，dp[0]表示当前结点不偷所能取得的最大价值，dp[1]则是偷
2.递推公式：看代码注释
3.初始化：当前节点为空时，返回{0，0}
4.遍历顺序：后序遍历
'''
class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        return max(self.robTree(root))
    def robTree(self, cur):
        if cur is None:
            return [0, 0]
        left = self.robTree(cur.left)
        right = self.robTree(cur.right)
        # 不偷
        val1 = max(left[0], left[1]) + max(right[0], right[1])
        # 偷
        val2 = cur.val + left[0] + right[0]
        return [val1, val2]