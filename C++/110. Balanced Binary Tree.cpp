/*
1.ตÝน้
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
    int getHeight(TreeNode* node) {
        if (node == NULL) return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        if (left == -1 || right == -1) return -1;
        int diff = abs(left - right);
        if (diff > 1) return -1;
        else return 1 + max(left, right);
    }
    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        if (height == -1) return false;
        else return true;
    }
};
