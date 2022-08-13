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
    TreeNode* traversal(vector<int>& nums, int begin, int end) {
        if (begin >= end) return NULL;
        int max = nums[begin];
        int max_index = begin;
        for (int i = begin; i < end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                max_index = i;
            }
        }
        TreeNode* node = new TreeNode(max);
        node->left = traversal(nums, begin, max_index);
        node->right = traversal(nums, max_index + 1, end);
        return node;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return traversal(nums, 0, nums.size());
    }
};