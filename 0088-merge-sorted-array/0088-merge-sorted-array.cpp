class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //two pointer
        // The code copies each element from nums2 to the end of nums1, 
        //and then sorts the entire nums1 array 
        //to make sure it is sorted in ascending order.
        for (int j = 0, i = m; j<n; j++){
            nums1[i++] = nums2[j];
        }
        sort(nums1.begin(),nums1.end());
    }
};