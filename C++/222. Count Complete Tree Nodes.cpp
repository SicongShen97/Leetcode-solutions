/*
1.µÝ¹é
2.±éÀú
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
 //     int countNodes(TreeNode* root) {
 //         if (!root) return 0;
 //         int left = countNodes(root->left);
 //         int right = countNodes(root->right);
 //         return left + right + 1;
 //     }
 // };

class Solution {
public:
    int countNodes(TreeNode* root) {
        queue<TreeNode*> que;
        if (root == NULL) return 0;
        que.push(root);
        int res = 0;
        while (!que.empty()) {
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front(); que.pop();
                res++;
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return res;
    }
};