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
 //     TreeNode* insertIntoBST(TreeNode* root, int val) {
 //         if (!root){
 //             return new TreeNode(val);
 //         } 
 //         if (root->val > val) root->left = insertIntoBST(root->left, val);
 //         else root->right = insertIntoBST(root->right, val);
 //         return root;
 //     }
 // };

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) return new TreeNode(val);
        TreeNode* pre = NULL;
        TreeNode* cur = root;
        while (cur) {
            if (cur->val > val) {
                pre = cur;
                cur = cur->left;
            }
            else {
                pre = cur;
                cur = cur->right;
            }
        }
        if (pre->val > val) pre->left = new TreeNode(val);
        else pre->right = new TreeNode(val);
        return root;
    }
};