# 用单调队列来从大到小存放滑动窗口的值
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        class MyQue:
            def __init__(self):
                self.que = []

            def push(self, val):
                while self.que and self.que[-1] < val:
                    self.que.pop(-1)
                self.que.append(val)

            def pop(self, val):
                if self.que and self.que[0] == val:
                    self.que.pop(0)

            def empty(self):
                return len(self.que) == 0

            def front(self):
                return self.que[0]

        que = MyQue()
        res = []
        for i in range(k):
            que.push(nums[i])
        res.append(que.front())
        for i in range(k, len(nums)):
            que.pop(nums[i - k])
            que.push(nums[i])
            res.append(que.front())
        return res