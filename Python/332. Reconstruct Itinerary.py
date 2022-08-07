'''
回溯：横向遍历目的地，纵横向递归出发地
'''


class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        tickets_dict = collections.defaultdict(list)
        for item in tickets:
            tickets_dict[item[0]].append(item[1])
        path = ["JFK"]

        def backtrack(start, numTickets):
            nonlocal tickets_dict
            nonlocal path
            if len(path) == numTickets + 1:
                return True
            tickets_dict[start].sort()
            for i in range(len(tickets_dict[start])):
                des = tickets_dict[start].pop(0)
                path.append(des)
                if backtrack(des, numTickets):
                    return True
                des = path.pop()
                tickets_dict[start].append(des)
            return False

        backtrack("JFK", len(tickets))
        return path