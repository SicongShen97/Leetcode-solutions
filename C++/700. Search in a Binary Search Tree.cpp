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
 //     TreeNode* searchBST(TreeNode* root, int val) {
 //         if (!root) return NULL;
 //         if (root->val == val) return root;
 //         if (root->val < val) return searchBST(root->right, val);
 //         else return searchBST(root->left, val);
 //     }
 // };

 // class Solution {
 // public:
 //     TreeNode* searchBST(TreeNode* root, int val) {
 //         stack<TreeNode*>st;
 //         st.push(root);
 //         while (!st.empty()){
 //             TreeNode* cur = st.top(); st.pop();
 //             if (cur != NULL){
 //                 if (cur->right) st.push(cur->right);
 //                 st.push(cur);
 //                 st.push(NULL);
 //                 if (cur->left) st.push(cur->left);
 //             }else{
 //                 TreeNode* cur = st.top(); st.pop();
 //                 if (cur->val < val) continue;
 //                 else if (cur->val == val) return cur;
 //                 else return NULL;
 //             }
 //         }
 //         return NULL;
 //     }
 // };

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return root;
        while (root) {
            if (root->val == val) return root;
            else if (root->val < val) root = root->right;
            else root = root->left;
        }
        return NULL;
    }
};