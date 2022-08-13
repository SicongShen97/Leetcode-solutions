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
 //     int sumOfLeftLeaves(TreeNode* root) {
 //         if (root == NULL) return 0;
 //         int temp = 0;
 //         if (root->left && !root->left->left && !root->left->right){
 //             temp = root->left->val;
 //         }
 //         return temp + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
 //     }
 // };

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        int res = 0;
        while (!st.empty()) {
            TreeNode* cur = st.top(); st.pop();
            if (cur->left && !cur->left->left && !cur->left->right) {
                res += cur->left->val;
            }
            if (cur->right) st.push(cur->right);
            if (cur->left) st.push(cur->left);
        }
        return res;
    }
};