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
 //     int res = INT_MAX;
 //     TreeNode* pre = NULL;
 //     void traversal(TreeNode* root){
 //         if (!root) return;
 //         traversal(root->left);
 //         if (pre) res = min(res, root->val - pre->val);
 //         pre = root;
 //         traversal(root->right);
 //     }
 //     int getMinimumDifference(TreeNode* root) {
 //         traversal(root);
 //         return res;
 //     }
 // };

class Solution {
public:
    int res = INT_MAX;
    TreeNode* pre = NULL;
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
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
                if (pre) res = min(res, cur->val - pre->val);
                pre = cur;
            }
        }
        return res;
    }
};