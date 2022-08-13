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
 //     TreeNode* pre = NULL;
 //     bool isValidBST(TreeNode* root) {
 //         if (!root) return true;
 //         bool left = isValidBST(root->left);
 //         if (pre && pre->val >= root->val) return false;
 //         pre = root;
 //         bool right = isValidBST(root->right);
 //         return left&&right;
 //     }
 // };

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        TreeNode* pre = NULL;
        while (!st.empty()) {
            TreeNode* cur = st.top(); st.pop();
            if (cur != NULL) {
                if (cur->right) st.push(cur->right);
                st.push(cur);
                st.push(NULL);
                if (cur->left) st.push(cur->left);
            }
            else {
                TreeNode* cur = st.top(); st.pop();
                if (pre && pre->val >= cur->val) return false;
                pre = cur;
            }
        }
        return true;
    }
};