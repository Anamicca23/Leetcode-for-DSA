class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # Using two pointers i and j, where i iterates over even indices and j iterates over odd indices.
        i, j = 0, 1
        while i < len(A):
            # Find the first even element at an even index.
            while i < len(A) and A[i] % 2 == 0:
                i += 2

            # Find the first odd element at an odd index.
            while j < len(A) and A[j] % 2 == 1:
                j += 2

            # Swap the even element at an even index with the odd element at an odd index.
            if i < len(A):
                A[i], A[j] = A[j], A[i]

        return A   