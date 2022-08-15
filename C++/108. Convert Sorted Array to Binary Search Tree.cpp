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
 //     TreeNode* createBST(vector<int>& nums, int begin, int end){
 //         if (begin >= end) return NULL;
 //         int mid = (begin + end) / 2;
 //         TreeNode* node = new TreeNode(nums[mid]);
 //         node->left = createBST(nums, begin, mid);
 //         node->right = createBST(nums, mid+1, end);
 //         return node;
 //     }
 //     TreeNode* sortedArrayToBST(vector<int>& nums) {
 //         return createBST(nums, 0, nums.size());
 //     }
 // };

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return NULL;
        queue<TreeNode*> que;
        TreeNode* root = new TreeNode(0);
        que.push(root);
        queue<int> leftQue;
        queue<int> rightQue;
        leftQue.push(0);
        rightQue.push(nums.size() - 1);
        while (!que.empty()) {
            TreeNode* node = que.front(); que.pop();
            int left = leftQue.front(); leftQue.pop();
            int right = rightQue.front(); rightQue.pop();
            int mid = left + (right - left) / 2;
            node->val = nums[mid];
            if (left < mid) {
                node->left = new TreeNode(0);
                que.push(node->left);
                leftQue.push(left);
                rightQue.push(mid - 1);
            }
            if (mid < right) {
                node->right = new TreeNode(0);
                que.push(node->right);
                leftQue.push(mid + 1);
                rightQue.push(right);
            }
        }
        return root;
    }
};