class Solution:
    def canReach(self, A, cur):
        if cur < 0 or cur >= len(A) or A[cur] < 0:
            return False
        A[cur] *= -1
        return (
            A[cur] == 0
            or self.canReach(A, cur + A[cur])
            or self.canReach(A, cur - A[cur])
        )
