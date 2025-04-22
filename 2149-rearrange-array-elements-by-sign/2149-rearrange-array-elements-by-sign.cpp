class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos, neg;
        int n = nums.size();
        vector<int> ret;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < 0) neg.push_back(i);
            else pos.push_back(i);
        }
        bool takepos = true;
        int i = 0, j =0;
        while(i < pos.size() || j < neg.size()){
            if(takepos){
                ret.push_back(nums[pos[i]]);
                i++;
            }else{
                ret.push_back(nums[neg[j]]);
                j++;
            }
            takepos = !takepos;
        }
        return ret;
    }
};