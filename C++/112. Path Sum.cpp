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
 //     int sum = 0;
 //     bool hasPathSum(TreeNode* root, int targetSum) {
 //         if (root == NULL){
 //             return false;
 //         }
 //         sum += root->val;
 //         if (!root->left and !root->right){
 //             if (sum == targetSum) return true;
 //         }
 //         if (root->left){
 //             if (hasPathSum(root->left, targetSum)) return true;
 //         }
 //         if (root->right){
 //             if (hasPathSum(root->right, targetSum)) return true;
 //         }
 //         sum -= root->val;
 //         return false;
 //     }
 // };

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL) return false;
        stack<pair<TreeNode*, int>>st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while (!st.empty()) {
            pair<TreeNode*, int> cur = st.top(); st.pop();
            if (!cur.first->left && !cur.first->right && cur.second == targetSum) return true;
            if (cur.first->right) {
                st.push(pair<TreeNode*, int>(cur.first->right, cur.second + cur.first->right->val));
            }
            if (cur.first->left) {
                st.push(pair<TreeNode*, int>(cur.first->left, cur.second + cur.first->left->val));
            }
        }
        return false;
    }
};