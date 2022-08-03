/*
贪心：从后往前遍历，当strNum[i-1]>strNum[i]时，strNum[i-1]--, strNum[i] = 1
*/
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string strNum = to_string(n);
        int flag;
        for (int i = strNum.size() - 1; i > 0; i--) {
            if (strNum[i] < strNum[i - 1]) {
                strNum[i - 1]--;
                flag = i;
            }
        }
        for (int i = flag; i < strNum.size(); i++) {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};