class MyQueue:

    def __init__(self):
        self.inSt = []
        self.outSt = []
    def push(self, x: int) -> None:
        self.inSt.append(x)

    def pop(self) -> int:
        if self.outSt:
            return self.outSt.pop(-1)
        while self.inSt:
            self.outSt.append(self.inSt.pop(-1))
        return self.outSt.pop(-1)

    def peek(self) -> int:
        res = self.pop()
        self.outSt.append(res)
        return res

    def empty(self) -> bool:
        return not self.inSt and not self.outSt


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()