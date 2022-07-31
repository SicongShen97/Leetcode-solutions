'''
贪心：先考虑右边大于左边情况，从前往后遍历，大于就加一，再考虑左边大于右边情况，从后往前遍历，大于就加一，取最大值
'''
class Solution:
    def candy(self, ratings: List[int]) -> int:
        candy = [1 for _ in range(len(ratings))]
        for i in range(1, len(candy)):
            if ratings[i] > ratings[i-1]:
                candy[i] = candy[i-1] + 1;
        for i in range(len(candy)-2, -1, -1):
            if ratings[i] > ratings[i+1]:
                candy[i] = max(candy[i+1] + 1, candy[i])
        return sum(candy)