/*
1.µü´ú
2.µÝ¹é
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

 // class Solution {
 // public:
 //     TreeNode* trimBST(TreeNode* root, int low, int high) {
 //         if (!root) return root;
 //         if (root->val < low) return trimBST(root->right, low, high);
 //         else if (root->val > high) return trimBST(root->left, low, high);
 //         else{
 //             root->left = trimBST(root->left, low, high);
 //             root->right = trimBST(root->right, low, high);
 //         }
 //         return root;
 //     }
 // };

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        if (!root) return root;
        while ((root != NULL) && (root->val < low || root->val > high)) {
            if (root->val < low) root = root->right;
            else if (root->val > high) root = root->left;
            else break;
        }
        if (!root) return root;
        TreeNode* node = root;
        while (node) {
            while (node->left && node->left->val < low) {
                node->left = node->left->right;
            }
            node = node->left;
        }
        node = root;
        while (node) {
            while (node->right && node->right->val > high) {
                node->right = node->right->left;
            }
            node = node->right;
        }
        return root;
    }
};