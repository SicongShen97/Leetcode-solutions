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
 //     int maxDepth(TreeNode* root) {
 //         if (!root) return 0;
 //         int lheight = maxDepth(root->left);
 //         int rheight = maxDepth(root->right);
 //         return 1 + max(lheight, rheight);
 //     }
 // };

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if (root == NULL) return depth;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            depth++;
            int size = que.size();
            for (int i = 0; i < size; i++) {
                TreeNode* cur = que.front(); que.pop();
                if (cur->left) que.push(cur->left);
                if (cur->right) que.push(cur->right);
            }
        }
        return depth;
    }
};