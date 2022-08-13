/*
ตÝน้
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
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() == 0) return NULL;
        TreeNode* node = new TreeNode(postorder.back());
        int mid = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == postorder.back()) {
                mid = i;
                break;
            }
        }
        vector<int>left_inorder(inorder.begin(), inorder.begin() + mid);
        vector<int>right_inorder(inorder.begin() + mid + 1, inorder.end());
        vector<int>left_postorder(postorder.begin(), postorder.begin() + mid);
        vector<int>right_postorder(postorder.begin() + mid, postorder.end() - 1);

        node->left = traversal(left_inorder, left_postorder);
        node->right = traversal(right_inorder, right_postorder);
        return node;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return traversal(inorder, postorder);
    }
};