// 贪心算法：把胃口大的孩子先用最大尺寸的饼干喂
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = s.size() - 1;
        int res = 0;
        for (int i = g.size() - 1; i >= 0; i--) {
            if (index >= 0 && g[i] <= s[index]) {
                index--;
                res += 1;
            }
        }
        return res;
    }
};