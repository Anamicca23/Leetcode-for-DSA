class Solution {
    public int[][] mergeArrays(int[][] nums1, int[][] nums2) {
        int n1=nums1.length,n2=nums2.length,i=0,j=0;
        ArrayList<int []>ans=new ArrayList();
        while(i<n1&& j<n2){
            if(nums1[i][0]==nums2[j][0]){
                ans.add(new int[]{nums1[i][0],nums1[i][1]+nums2[j][1]});
                i++;
                j++;
            }
            else if(nums1[i][0]<nums2[j][0]){
                ans.add(nums1[i]);
                i++;
            }
            else{
                ans.add(nums2[j]);
                j++;
            }
        }
        while(i<n1){
            ans.add(nums1[i++]);
        }
        while(j<n2){
            ans.add(nums2[j++]);
        }
        return ans.toArray(new int[ans.size()][]);
    }
}