class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        Arrays.sort(nums1); // Sort nums1 in ascending order
        Arrays.sort(nums2); // Sort nums2 in ascending order
        int n = nums1.length;
        int m = nums2.length;
        Set<Integer> set = new HashSet<>(); // Using a set to store unique elements

        int i = 0, j = 0;
        // Two pointer approach to find the intersection of sorted arrays
        while (i < n && j < m) {
            if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] < nums2[j])
                i++;
            else {
                set.add(nums1[i++]); // Insert common element into the set
                j++;
            }
        }

        int[] ans = new int[set.size()];
        int index = 0;
        // Convert set elements to an array for returning the result
        for (int num : set) {
            ans[index++] = num;
        }
        return ans;
    }
}
