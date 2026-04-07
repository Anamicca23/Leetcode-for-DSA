class Robot:

    def __init__(self, width: int, height: int):
        self.cur = [0, 0]
        self.curDir = 0
        self.width = width
        self.height = height
        self.dir_mapping = {0: "East", 1: "North", 2: "West", 3: "South"}
        self.mod = 2 * (self.width + self.height - 2)

    def step(self, num: int) -> None:

        if num >= self.mod:
            num %= self.mod
            if self.cur == [0, 0] and self.curDir == 0:
                self.curDir = 3

        while num > 0:

            if self.curDir == 0:
                num, self.cur[0] = (
                    num - (steps := min(num, (self.width - self.cur[0] - 1))),
                    self.cur[0] + steps,
                )
            elif self.curDir == 1:
                num, self.cur[1] = (
                    num - (steps := min(num, (self.height - 1 - self.cur[1]))),
                    self.cur[1] + steps,
                )
            elif self.curDir == 2:
                num, self.cur[0] = (
                    num - (steps := min(num, self.cur[0])),
                    self.cur[0] - steps,
                )
            else:
                num, self.cur[1] = (
                    num - (steps := min(num, self.cur[1])),
                    self.cur[1] - steps,
                )

            if num > 0:
                self.curDir = (self.curDir + 1) % 4

    def getPos(self) -> List[int]:
        return self.cur

    def getDir(self) -> str:
        return self.dir_mapping[self.curDir]


# Your Robot object will be instantiated and called as such:
# obj = Robot(width, height)
# obj.step(num)
# param_2 = obj.getPos()
# param_3 = obj.getDir()
