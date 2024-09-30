class CustomStack:

    def __init__(self, maxSize: int):
        self.stack = []
        self.maxSize = maxSize
        self.inc = []

    def push(self, x: int) -> None:
        if len(self.stack) == self.maxSize:
            return
        self.stack.append(x)
        self.inc.append(0)

    def pop(self) -> int:
        if len(self.stack) == 0:
            return -1
        if len(self.inc) > 1:
            self.inc[-2] += self.inc[-1]
        return self.stack.pop() + self.inc.pop()

    def increment(self, k: int, val: int) -> None:
        k = min(k, len(self.stack))
        if k == 0:
            return
        self.inc[k - 1] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)