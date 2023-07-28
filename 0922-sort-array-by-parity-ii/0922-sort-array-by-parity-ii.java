class Solution {
    public int[] sortArrayByParityII(int[] A) {
        // Using two pointers i and j, where i iterates over even indices and j iterates over odd indices.
        for (int i = 0, j = 1; i < A.length; i += 2, j += 2) {
            // Find the first even element at an even index.
            while (i < A.length && A[i] % 2 == 0)
                i += 2;

            // Find the first odd element at an odd index.
            while (j < A.length && A[j] % 2 == 1)
                j += 2;

            // Swap the even element at an even index with the odd element at an odd index.
            if (i < A.length)
                swap(A, i, j);
        }
        return A;
    }

    // Helper method to swap two elements in an array.
    private void swap(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}