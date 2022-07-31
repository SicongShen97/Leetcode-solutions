/*
贪心：每个加油站的gas-cost就是所能获得的剩余gas，从0开始累计这些剩余，如果到i开始小于0，那起点肯定是i+1之后
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