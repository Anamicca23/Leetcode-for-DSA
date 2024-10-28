class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,int>mp;
        sort(nums.begin(),nums.end());
        int maxs=0;
        for(int i=0; i<nums.size();i++){
            int root = (int)sqrt(nums[i]);
            if(root*root == nums[i] and mp.find(root)!=mp.end()){
                mp[nums[i]]= mp[root]+1;
            }else{
                mp[nums[i]]=1;
            }
            maxs = max(maxs,mp[nums[i]]);
        }
        return maxs<2?-1:maxs;
    }
};