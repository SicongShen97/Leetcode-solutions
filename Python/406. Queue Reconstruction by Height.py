'''
贪心算法：
优先按身高从高到低排，若身高相同，k低的排前面，然后从前往后进行插入
'''
class Solution:
    def reconstructQueue(self, people: List[List[int]]) -> List[List[int]]:
        people.sort(key=lambda x: (-x[0], x[1]))
        que = []
        for p in people:
            que.insert(p[1], p)
        return que