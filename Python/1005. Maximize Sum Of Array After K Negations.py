'''
贪心算法：优先把最小的负数取正，如有剩余，对最小正数取反
'''
class Solution:
    def largestSumAfterKNegations(self, nums: List[int], k: int) -> int:
        nums = sorted(nums, key=abs, reverse=True)
        for i in range(len(nums)):
            if nums[i]<0 and k>0:
                nums[i] *= -1
                k -= 1
        if k%2 == 1:
            nums[-1] *= -1
        return sum(nums)