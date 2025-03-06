
# x ^ 0 = x; x ^ x = 0; x ^ y = y ^ x
# x ^ y = w; w ^ x = y; w ^ y = x
class Solution:
    def findMissingAndRepeatedValues(self, grid: List[List[int]]) -> List[int]:
        n = len(grid)
        visited = [False] * (n * n + 1)
        repeated_value = -1
        # xor of all grid elements (b is missing, a will be canceled)
        xor_without_ab = 0  
        # xor of (1..n^2)
        xor_of_all = 0
        # counter (1..n^2)
        cnt = 1

        for row in grid:
            for element in row:
                xor_without_ab ^= element
                xor_of_all ^= cnt
                cnt += 1
                if repeated_value == -1:
                    if visited[element]:
                        repeated_value = element
                    else:
                        visited[element] = True

        # a ^ b = xor_without_ab ^ xor_of_all
        # b = a ^ b ^ repeated_value
        missing_value = xor_without_ab ^ xor_of_all ^ repeated_value
        return [repeated_value, missing_value]