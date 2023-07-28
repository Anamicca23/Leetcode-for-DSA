class Solution {
    public int[] intersect(int[] nums1, int[] nums2) {
        Arrays.sort(nums1); // Sort nums1 in ascending order
        Arrays.sort(nums2); // Sort nums2 in ascending order
        int n = nums1.length;
        int m = nums2.length;

        List<Integer> ansList = new ArrayList<>();
        int i = 0, j = 0;
        // Two pointer approach to find the intersection of sorted arrays
        while (i < n && j < m) {
            if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] < nums2[j])
                i++;
            else {
                ansList.add(nums1[i]); // Add common element to the list
                i++;
                j++;
            }
        }

        // Convert the list to an array for returning the result
        int[] ans = new int[ansList.size()];
        for (int k = 0; k < ansList.size(); k++) {
            ans[k] = ansList.get(k);
        }
        return ans;
    }
}
