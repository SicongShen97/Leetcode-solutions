/*
1.»ØËÝ
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
    vector<int> path;
    vector<string> res;
    void backtrack(TreeNode* node) {
        path.push_back(node->val);
        if (!node->left && !node->right) {
            string sPath;
            for (int num : path) {
                sPath += to_string(num);
                sPath += "->";
            }
            res.push_back(sPath.substr(0, sPath.size() - 2));
        }
        if (node->left) {
            backtrack(node->left);
        }
        if (node->right) {
            backtrack(node->right);
        }
        path.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        path.clear();
        res.clear();
        backtrack(root);
        return res;
    }
};