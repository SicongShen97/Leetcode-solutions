/*
贪心：每次记录当前的覆盖范围和下一次的覆盖范围，当到达当前覆盖范围时，步数加1
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int cur = 0;
        int next = 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            next = max(next, i + nums[i]);
            if (i == cur) {
                res++;
                cur = next;
            }
        }
        return res;
    }
};