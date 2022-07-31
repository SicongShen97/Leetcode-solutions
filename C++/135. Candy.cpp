/*
贪心：先考虑右边大于左边情况，从前往后遍历，大于就加一，再考虑左边大于右边情况，从后往前遍历，大于就加一，取最大值
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        if (ratings.size() == 1) return 1;
        vector<int> candyVec(ratings.size(), 1);
        for (int i = 1; i < candyVec.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                candyVec[i] = candyVec[i - 1] + 1;
            }
        }
        for (int i = candyVec.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candyVec[i] = max(candyVec[i + 1] + 1, candyVec[i]);
            }
        }
        int res = 0;
        for (int c : candyVec) res += c;
        return res;
    }
};