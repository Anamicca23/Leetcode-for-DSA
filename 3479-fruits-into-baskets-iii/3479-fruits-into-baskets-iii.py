class SegmentTree:
    def __init__(self, n: int, baskets: list[int]) -> None:
        self.seg_tree: list[int] = [0] * (4 * 100 + 1)
        self.build(1, 0, n, baskets)
    
    def build(self, parent: int, left: int, right: int, baskets: list[int]) -> None:
        if left == right:
            self.seg_tree[parent] = baskets[left]
            return
        middle: int = left + ((right - left) >> 1)
        self.build(parent << 1, left, middle, baskets)
        self.build(parent << 1 | 1, middle + 1, right, baskets)
        self.seg_tree[parent] = max(self.seg_tree[parent << 1], self.seg_tree[parent << 1 | 1])
    
    def query(self, parent: int, left: int, right: int, target: int) -> int:
        if self.seg_tree[parent] < target: return -1
        elif left == right: return left
        middle: int = left + ((right - left) >> 1)
        if self.seg_tree[parent << 1] >= target: return self.query(parent << 1, left, middle, target)
        return self.query(parent << 1 | 1, middle + 1, right, target)
    
    def update(self, parent: int, left: int, right: int, pos: int, val: int) -> None:
        if left == right:
            self.seg_tree[parent] = val
            return
        middle: int = left + ((right - left) >> 1)
        if pos <= middle: self.update(parent << 1, left, middle, pos, val)
        else: self.update(parent << 1 | 1, middle + 1, right, pos, val)
        self.seg_tree[parent] = max(self.seg_tree[parent << 1], self.seg_tree[parent << 1 | 1])

class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n: int = len(fruits)
        st: SegmentTree = SegmentTree(n - 1, baskets)
        output: int = 0
        for fruit in fruits:
            pos: int = st.query(1, 0, n - 1, fruit)
            if pos == -1: output += 1
            else: st.update(1, 0, n - 1, pos, -1)
        return output