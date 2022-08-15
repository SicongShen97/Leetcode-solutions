/*
1.µÝ¹é
2.µü´ú
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
 //     TreeNode* deleteNode(TreeNode* root, int key) {
 //         if (!root) return root;
 //         if (root->val < key) root->right = deleteNode(root->right, key);
 //         else if (root->val > key) root->left = deleteNode(root->left, key);
 //         else{
 //             if (!root->left && !root->right) return NULL;
 //             else if (!root->left) return root->right;
 //             else if (!root->right) return root->left;
 //             else{
 //                 TreeNode* cur = root->right;
 //                 TreeNode* parent = NULL;
 //                 while (cur){
 //                     parent = cur;
 //                     cur = cur->left;
 //                 }
 //                 parent->left = root->left;
 //                 return root->right;
 //             }
 //         }
 //         return root;
 //     }
 // };

class Solution {
public:
    TreeNode* deleteOneNode(TreeNode* node) {
        if (!node->left && !node->right) return NULL;
        else if (!node->left) return node->right;
        else if (!node->right) return node->left;
        else {
            TreeNode* temp = node->right;
            while (temp->left) temp = temp->left;
            temp->left = node->left;
            return node->right;
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;
        TreeNode* cur = root;
        TreeNode* parent = NULL;
        while (cur) {
            if (cur->val == key) break;
            parent = cur;
            if (cur->val > key) cur = cur->left;
            else cur = cur->right;
        }
        if (!cur) return root;
        if (!parent) return deleteOneNode(cur);
        if (parent->left && parent->left->val == key) parent->left = deleteOneNode(cur);
        if (parent->right && parent->right->val == key) parent->right = deleteOneNode(cur);
        return root;
    }
};