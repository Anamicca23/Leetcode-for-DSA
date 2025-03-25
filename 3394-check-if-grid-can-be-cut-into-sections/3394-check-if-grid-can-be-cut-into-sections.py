class Solution:
    def canCut(self, rectangles, dim):
        rectangles.sort(key = lambda rectangle: rectangle[dim])
        n_sections = 0
        last_end = 0
        for rectangle in rectangles:
            if last_end <= rectangle[dim]:
                n_sections += 1
                if n_sections == 3:
                    return True
            end = rectangle[dim+2]
            if last_end < end:
                last_end = end
        return False
    def checkValidCuts(self, n: int, rectangles: List[List[int]]) -> bool:
        for dim in range(2):
            if self.canCut(rectangles, dim):
                return True
        return False