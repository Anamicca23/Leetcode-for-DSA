class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        // Two pointers
        // The code copies each element from nums2 to the end of nums1,
        // and then sorts the entire nums1 array
        // to make sure it is sorted in ascending order.
        int i = m;
        for (int j = 0; j < n; j++) {
            nums1[i] = nums2[j];
            i++;
        }
        Arrays.sort(nums1);
    }
}
