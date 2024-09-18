class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto comp = [](int & as,int& bs){
              string a= to_string(as);
              string b= to_string(bs);
              return a+b>b+a;
        };
        sort(nums.begin(),nums.end(),comp);
        if(nums[0]==0)return "0";
        string ans ="";
        for(auto &n:nums){
            ans+= to_string(n);
        }
        return ans;
    }
};