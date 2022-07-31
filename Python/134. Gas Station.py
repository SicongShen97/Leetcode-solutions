'''
贪心：每个加油站的gas-cost就是所能获得的剩余gas，从0开始累计这些剩余，如果到i开始小于0，那起点肯定是i+1之后
'''
class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        start = 0
        curSum = 0
        totSum = 0
        res = 0
        for i in range(len(gas)):
            res = gas[i] - cost[i]
            curSum += res
            totSum += res
            if curSum < 0:
                start = i + 1
                curSum = 0
        if totSum < 0:
            return -1
        return start