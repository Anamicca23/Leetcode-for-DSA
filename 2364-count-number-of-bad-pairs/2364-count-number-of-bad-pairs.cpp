class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n=nums.size();
        long long totalPairs=(n*(n-1))/2;
        unordered_map<int ,int>mp;
        long long notBadPairs=0;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]-i]!=0)
            {
                notBadPairs+=mp[nums[i]-i];
            }
            mp[nums[i]-i]+=1;
        }

        return totalPairs-notBadPairs;
    }
};