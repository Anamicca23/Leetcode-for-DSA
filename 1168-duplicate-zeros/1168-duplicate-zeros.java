public class Solution {
    public void duplicateZeros(int[] arr) {
        int pos = 0; // Variable to track the position of the last non-zero element
        int ptr = 0; // Variable to track the current index in the for loop

        // First loop: Find positions for duplicating zeros and update `pos` and `ptr`
        for (int i = 0, ct = 0; i < arr.length; i++, ct++) {
            if (arr[ct] == 0) {
                i++; // Increment `i` to skip the next element when a zero is encountered
            } else {
                pos = ct; // Update `pos` with the index of the last non-zero element
                ptr = i;  // Update `ptr` with the current index in the for loop
            }
        }

        // Second loop: Perform duplication and shifting
        for (int i = ptr; i >= 0; i--) {
            arr[i] = arr[pos]; // Shift the elements to the right by assigning the value of the last non-zero element

            // Duplicate zeros by inserting 0 in the correct position
            if (arr[pos] == 0 && i != 0) {
                arr[--i] = 0; // Decrement `i` and assign 0 to the previous index
            }

            pos--; // Move to the previous non-zero element
        }

        // Third loop: Set remaining elements to 0
        for (int i = ptr + 1; i < arr.length; i++) {
            arr[i] = 0; // Set the remaining elements to 0
        }
    }
}