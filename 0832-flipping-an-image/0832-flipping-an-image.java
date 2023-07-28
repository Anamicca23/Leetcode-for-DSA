class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        // Flips each row of the image horizontally and inverts the pixel values within each row using bitwise XOR operations.
        // By swapping the values from left and right symmetric positions, it effectively flips the image horizontally.
        // The XOR operation with 1 inverts the pixel values.
        // The solution performs these operations in-place, directly modifying the input image array.

        // Store the number of rows and columns in the image array, respectively.
        int n = image.length;
        int m = image[0].length;

        // Iterate over each row of the image array.
        for (int i = 0; i < n; i++) {
            // Iterate over the elements up to the middle column.
            for (int j = 0; j < (m + 1) / 2; j++) {
                // Compute the bitwise XOR of the current element (image[i][j]) and 1 (^1).
                // This effectively inverts the pixel value (0 becomes 1, and 1 becomes 0).
                int temp = image[i][j] ^ 1;

                // Assign the inverted value to the current element.
                image[i][j] = image[i][m - 1 - j] ^ 1;

                // Compute the bitwise XOR of the element at the mirrored position.
                // Assign the inverted value to the mirrored element.
                image[i][m - 1 - j] = temp;
            }
        }

        // After processing all rows and elements, the modified image is returned.
        return image;
    }
}
