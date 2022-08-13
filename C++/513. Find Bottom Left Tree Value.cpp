/*
1.�ݹ�
2.����
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
 //     int maxLen = INT_MIN;
 //     int maxLeftValue;
 //     void backtrack(TreeNode* node, int len){
 //         if (len > maxLen){
 //             maxLen = len;
 //             maxLeftValue = node->val;
 //         }
 //         if (node->left){
 //             backtrack(node->left, len+1);
 //         }
 //         if (node->right){
 //             backtrack(node->right, len+1);
 //         }
 //     }
 //     int findBottomLeftValue(TreeNode* root) {
 //         backtrack(root, 1);
 //         return maxLeftValue;
 //     }
 // };

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int res = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front(); que.pop();
                if (i == 0) res = cur->val;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return res;
    }
};