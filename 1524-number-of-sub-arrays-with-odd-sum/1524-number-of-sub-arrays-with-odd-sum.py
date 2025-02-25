    def numOfSubarrays(self, arr: List[int]) -> int:
        odd = sum = 0
        for a in arr:
            sum += a
            odd += sum % 2
        return (odd + odd * (len(arr) - odd)) % (10 ** 9 + 7)