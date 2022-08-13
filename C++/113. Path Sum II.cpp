/*
ตÝน้
*/
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
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    int sum;
    void backtrack(TreeNode* root, int targetSum) {
        sum += root->val;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == targetSum) {
            res.push_back(path);
        }
        if (root->left) {
            backtrack(root->left, targetSum);
        }
        if (root->right) {
            backtrack(root->right, targetSum);
        }
        sum -= root->val;
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();
        path.clear();
        sum = 0;
        if (root == NULL) return res;
        backtrack(root, targetSum);
        return res;
    }
};