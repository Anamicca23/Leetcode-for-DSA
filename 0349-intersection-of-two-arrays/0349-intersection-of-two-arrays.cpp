class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end()); // Sort nums1 in ascending order
        sort(nums2.begin(), nums2.end()); // Sort nums2 in ascending order
        int n = nums1.size();
        int m = nums2.size();
        set<int> s; // Using a set to store unique elements

        int i = 0, j = 0;
        // Two pointer approach to find the intersection of sorted arrays
        while (i < n && j < m) {
            if (nums1[i] > nums2[j])
                j++;
            else if (nums1[i] < nums2[j])
                i++;
            else {
                s.insert(nums1[i]); // Insert common element into the set
                i++;
                j++;
            }
        }

        vector<int> ans;
        // Convert set elements to vector for returning the result
        for (auto i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};
