class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_set<int>st(nums.begin(),nums.end());
        int maxs=0;
        for(int &num: nums){
          long long curr=num;
          int strk=0;
          while(st.find(curr)!=st.end()){
            strk++;
            if(curr*curr>1e5){
                break;
            }
            curr=curr*curr;
          }
          maxs = max(maxs,strk);
        }
        return maxs<2?-1:maxs;
    }
};