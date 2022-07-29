/*
��̬�滮��
1.dp���京�壺
dp[i][0]:��nums[i]Ϊ����nums[i]Ϊ�ȵ���ڶ�������
dp[i][1]:��nums[i]Ϊ����nums[i]Ϊ�����ڶ�������
2.���ƹ�ʽ��
for (int j=0; j<i; j++){
    if (nums[i] > nums[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
    if (nums[i] < nums[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
}
3.��ʼ����dp[i][0] = 1, dp[i][1] = 1
4.����˳�򣺴�ǰ����
*/
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(2, 1));
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
                if (nums[i] < nums[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            }
            res = max(dp[i][0], dp[i][1]);
        }
        return res;
    }
};

/*
̰���㷨��
�ֲ����ţ�ɾ���������ϵĽڵ㣬���������ˣ���õ�������ֵ
*/
/*
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() <= 1) return nums.size();
        int pre = 0;
        int cur = 0;
        int res = 1;
        for (int i = 1; i < nums.size(); i++) {
            cur = nums[i] - nums[i - 1];
            if ((cur > 0 && pre <= 0) || (cur < 0 && pre >= 0)) {
                res += 1;
                pre = cur;
            }
        }
        return res;
    }
};
*/