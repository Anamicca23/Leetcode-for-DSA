class Solution {
public:
    static int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        const int n1=nums1.size(), n2=nums2.size();
        int dist=0;
        for(int i=0, j=0; i<n1 && j<n2; ){
            if (i<=j && nums1[i]<=nums2[j]) dist=max(dist, j-i), j++;
            else if (i<=j) i++;
            else j++;
        }
        return dist;
    }
};