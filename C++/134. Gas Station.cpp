/*
̰�ģ�ÿ������վ��gas-cost�������ܻ�õ�ʣ��gas����0��ʼ�ۼ���Щʣ�࣬�����i��ʼС��0�������϶���i+1֮��
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = 0;
        int curSum = 0;
        int totalSum = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            res = gas[i] - cost[i];
            curSum += res;
            totalSum += res;
            if (curSum < 0) {
                curSum = 0;
                start = i + 1;
            }
        }
        if (totalSum < 0) return -1;
        return start;
    }
};