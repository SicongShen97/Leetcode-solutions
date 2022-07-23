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
 ��̬�滮��
 1.ȷ��dp���京�壺ÿһ��ݹ��У�dp[0]��ʾ��ǰ��㲻͵����ȡ�õ�����ֵ��dp[1]����͵
 2.���ƹ�ʽ��������ע��
 3.��ʼ������ǰ�ڵ�Ϊ��ʱ������{0��0}
 4.����˳�򣺺������
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
        //͵cur
        int val1 = cur->val + left[0] + right[0];
        //��͵cur
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);
        return { val2, val1 };
    }
};