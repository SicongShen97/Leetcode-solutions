/*
̰�ģ�������������ȸ��ڵ�װ����ͷ�����ݷ���ֵ��0���ýڵ��޸��ǣ�1���ýڵ�������ͷ��2���ýڵ��и���
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
    int res = 0;
    int traversal(TreeNode* node) {
        if (node == nullptr) return 2;
        int left = traversal(node->left);
        int right = traversal(node->right);
        if (left == 0 || right == 0) {
            res++;
            return 1;
        }
        else if (left == 1 || right == 1) return 2;
        else return 0;
    }
    int minCameraCover(TreeNode* root) {
        if (traversal(root) == 0) res++;
        return res;
    }
};