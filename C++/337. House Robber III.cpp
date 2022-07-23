/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 /*
 动态规划：
 1.确定dp及其含义：每一层递归中，dp[0]表示当前结点不偷所能取得的最大价值，dp[1]则是偷
 2.递推公式：看代码注释
 3.初始化：当前节点为空时，返回{0，0}
 4.遍历顺序：后序遍历
 */
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> res = robTree(root);
        return max(res[0], res[1]);
    }
    vector<int> robTree(TreeNode* cur) {
        if (cur == NULL) return vector<int>{0, 0};
        vector<int> left = robTree(cur->left);
        vector<int> right = robTree(cur->right);
        //偷cur
        int val1 = cur->val + left[0] + right[0];
        //不偷cur
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return { val2, val1 };
    }
};