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
 //     void traversal(TreeNode* root){
 //         if (!root) return;
 //         traversal(root->right);
 //         root->val += sum;
 //         sum = root->val;
 //         traversal(root->left);
 //     }
 //     TreeNode* convertBST(TreeNode* root) {
 //         sum = 0;
 //         traversal(root);
 //         return root;
 //     }
 // };

class Solution {
public:
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return root;
        stack<TreeNode*> st;
        st.push(root);
        sum = 0;
        while (!st.empty()) {
            TreeNode* node = st.top(); st.pop();
            if (node) {
                if (node->left) st.push(node->left);
                st.push(node);
                st.push(NULL);
                if (node->right) st.push(node->right);
            }
            else {
                TreeNode* node = st.top(); st.pop();
                node->val += sum;
                sum = node->val;
            }
        }
        return root;
    }
};