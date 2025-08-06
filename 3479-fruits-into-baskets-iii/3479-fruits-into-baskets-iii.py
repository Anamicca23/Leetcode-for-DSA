class SegmentTree:
    def __init__(self, leaf_nodes):
        l = len(leaf_nodes)
        self.n = 2 ** math.ceil(math.log2(l))
        self.nodes = [0] * (2 * self.n)
        for i, val in enumerate(leaf_nodes):
            self.update(i + self.n, val)
    
    def update(self, i, val):
        self.nodes[i] = val
        while i > 1:
            i = i // 2
            self.nodes[i] = max(self.nodes[i*2], self.nodes[i*2+1])
    
    def find(self, target_val):
        if self.nodes[1] < target_val:
            return -1
        i = 1
        while i < self.n:
            if self.nodes[i * 2] >= target_val:
                i = i * 2
            else:
                i = i * 2 + 1
        return i
        
class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        s_t = SegmentTree(baskets)
        res = 0
        for val in fruits:
            node_id = s_t.find(val)
            if node_id != -1:
                s_t.update(node_id, -1)
            else:
                res += 1
        return res

