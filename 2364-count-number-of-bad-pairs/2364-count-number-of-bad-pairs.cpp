class Solution {
public:
    long long countBadPairs(vector<int>& nums){
        long long int b=nums.size(),g=0,k=0;
        for(int i=0;i<b;i++){
            nums[i]=i-nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<b-1;i++){
            if(nums[i]==nums[i+1]){k++;}
            else{g=g+(k*(k+1))/2;k=0;}
        }
        return (b*(b-1))/2-g-(k*(k+1))/2;
    }
};