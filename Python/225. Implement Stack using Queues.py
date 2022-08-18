class MyStack:

    def __init__(self):
        self.que = []

    def push(self, x: int) -> None:
        self.que.append(x)

    def pop(self) -> int:
        size = len(self.que) -1
        while (size):
            size -= 1
            self.que.append(self.que.pop(0))
        return self.que.pop(0)

    def top(self) -> int:
        res = self.pop()
        self.que.append(res)
        return res

    def empty(self) -> bool:
        return len(self.que) == 0


# Your MyStack object will be instantiated and called as such:
# obj = MyStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.empty()