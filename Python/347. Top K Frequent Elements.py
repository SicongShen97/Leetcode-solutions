# 用优先队列
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map_ = {}
        for num in nums:
            map_[num] = map_.get(num, 0) + 1
        pri_que = []
        import heapq
        for key, freq in map_.items():
            heapq.heappush(pri_que, (freq, key))
            if len(pri_que) > k:
                heapq.heappop(pri_que)
        res = [0]*k
        for i in range(k-1, -1, -1):
            res[i] = heapq.heappop(pri_que)[1]
        return res