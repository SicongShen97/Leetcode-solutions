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
 //     int max_count = 1;
 //     int cur_count = 1;
 //     vector<int> res;
 //     TreeNode* pre = NULL;
 //     void traversal(TreeNode* cur){
 //         if (cur == NULL) return;
 //         if (cur->left) traversal(cur->left);
 //         if (pre){
 //             if (pre->val == cur->val) cur_count++;
 //             else cur_count = 1;
 //         }
 //         pre = cur;
 //         if (cur_count == max_count){
 //             res.push_back(cur->val);
 //         }else if (cur_count > max_count){
 //             res.clear();
 //             res.push_back(cur->val);
 //             max_count = cur_count;
 //         }
 //         if (cur->right) traversal(cur->right);
 //     }
 //     vector<int> findMode(TreeNode* root) {
 //         res.clear();
 //         traversal(root);
 //         return res;
 //     }
 // };

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        stack<TreeNode*> st;
        int max_count = 1;
        int cur_count = 1;
        vector<int> res;
        TreeNode* pre = NULL;
        st.push(root);
        while (!st.empty()) {
            TreeNode* cur = st.top(); st.pop();
            if (cur) {
                if (cur->right) st.push(cur->right);
                st.push(cur);
                st.push(NULL);
                if (cur->left) st.push(cur->left);
            }
            else {
                TreeNode* cur = st.top(); st.pop();
                if (pre) {
                    if (pre->val == cur->val) cur_count++;
                    else cur_count = 1;
                }
                pre = cur;
                if (cur_count == max_count) res.push_back(cur->val);
                else if (cur_count > max_count) {
                    max_count = cur_count;
                    res.clear();
                    res.push_back(cur->val);
                }
            }
        }
        return res;
    }
};