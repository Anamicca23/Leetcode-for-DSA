class Solution:
    def maxAverageRatio(self, classes: List[List[int]], extraStudents: int) -> float:
        classes = [(num/denom - (num+1)/(denom+1), num, denom) for num, denom in classes]
        heapify(classes)
        if classes[0][0]==0:
            return 1
        for i in range(extraStudents):
            _, num, denom = heappop(classes)
            heappush(classes, ((num+1)/(denom+1) - (num+2)/(denom+2), num+1, denom+1))

        return sum([c[1]/c[2] for c in classes])/len(classes)