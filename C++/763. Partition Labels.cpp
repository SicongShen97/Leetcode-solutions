/*
̰���㷨����¼ÿ���ַ�����Զλ�ã��ָ���������
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int hash[27] = { 0 };
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] = i;
        }
        int left = 0;
        int right = 0;
        vector<int> vec;
        for (int i = 0; i < s.size(); i++) {
            right = max(right, hash[s[i] - 'a']);
            if (i == right) {
                vec.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return vec;
    }
};