/*
̰���㷨��
1.5Ԫֱ������
2.10Ԫ��5Ԫ
3.20Ԫ������10Ԫ��5Ԫ
*/
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0;
        int ten = 0;
        for (int bill : bills) {
            if (bill == 5) five++;
            else if (bill == 10) {
                if (five > 0) {
                    five--;
                    ten++;
                }
                else return false;
            }
            else {
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }
                else if (five >= 3) {
                    five -= 3;
                }
                else return false;
            }
        }
        return true;
    }
};