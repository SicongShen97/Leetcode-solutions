/*
贪心算法：优先把最小的负数取正，如有剩余，对最小正数取反
*/
class Solution {
public:
    static bool cmp(int a, int b) {
        return abs(a) > abs(b);
    }
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0 && k>0) {
                nums[i] *= -1;
                k -= 1;
            }
        }
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;
        int res = 0;
        for (int a : nums) res += a;
        return res;
    }
};