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

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        if (!root->left && !root->right) return 1;
        else if (root->left && !root->right) return 1 + minDepth(root->left);
        else if (root->right && !root->left) return 1 + minDepth(root->right);
        else {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            return min(left, right) + 1;
        }
    }
};

// class Solution {
// public:
//     int minDepth(TreeNode* root) {
//         queue<TreeNode*> que;
//         if (root) que.push(root);
//         int res = 0;
//         while (!que.empty()){
//             res++;
//             int size = que.size();
//             for (int i=0; i<size; i++){
//                 TreeNode* cur = que.front();
//                 que.pop();
//                 if (!cur->left && !cur->right) return res;
//                 if (cur->left) que.push(cur->left);
//                 if (cur->right) que.push(cur->right);
//             }
//         }
//         return res;
//     }
// };