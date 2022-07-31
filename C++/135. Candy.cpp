/*
̰�ģ��ȿ����ұߴ�������������ǰ������������ھͼ�һ���ٿ�����ߴ����ұ�������Ӻ���ǰ���������ھͼ�һ��ȡ���ֵ
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