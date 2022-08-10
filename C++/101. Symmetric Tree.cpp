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
 //     bool compare(TreeNode* left, TreeNode* right){
 //         if (!left && !right) return true;
 //         if (!left || !right) return false;
 //         if (left->val != right->val) return false;
 //         bool outside = compare(left->left, right->right);
 //         bool inside = compare(left->right, right->left);
 //         return outside&&inside;
 //     }
 //     bool isSymmetric(TreeNode* root) {
 //         return compare(root->left, root->right);
 //     }
 // };

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        vector<TreeNode*> vec = { root->left, root->right };
        while (!vec.empty()) {
            TreeNode* right = vec.back(); vec.pop_back();
            TreeNode* left = vec.back(); vec.pop_back();
            if (!right && !left) continue;
            if (!left || !right || left->val != right->val) return false;
            vec.push_back(left->left);
            vec.push_back(right->right);
            vec.push_back(left->right);
            vec.push_back(right->left);
        }
        return true;
    }
};

