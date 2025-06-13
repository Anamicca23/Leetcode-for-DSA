class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>ans;
        int temp1=0, temp2=0;
        int n1 = nums1.size(), n2 = nums2.size();
        while(temp1<n1 && temp2<n2){
            if(nums1[temp1][0]==nums2[temp2][0]){
                ans.push_back({nums1[temp1][0],nums1[temp1][1]+nums2[temp2][1]});
                temp1++;temp2++;
            }
            else if(nums1[temp1][0]<nums2[temp2][0]){
                ans.push_back({nums1[temp1][0],nums1[temp1][1]});
                temp1++;               
            }
            else{
                ans.push_back({nums2[temp2][0],nums2[temp2][1]});
                temp2++;                
            }
        }

        while(temp1<n1){
            ans.push_back({nums1[temp1][0],nums1[temp1][1]});
            temp1++; 
        }

        while(temp2<n2){
            ans.push_back({nums2[temp2][0],nums2[temp2][1]});
            temp2++; 
        }
        return ans; 
    }
};