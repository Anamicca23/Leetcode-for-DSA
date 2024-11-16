class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if(k==1) return nums;
        vector<int>ans;
        bool flag=true;
        int j=1;
        int i=0;
        while(j<nums.size()) {
            while(j<nums.size()) {
                if(nums[j]!=nums[j-1]+1) {
                        flag=false;
                        break;
                    }
                j++;
            }
            //count tells the size of the continuous array that satisfy given condition
            int count=j-i+1-k;
            
            //for indices=count we will push back the max element in ans array
            while(count>0) {
                ans.push_back(nums[i+k-1]);
                count--;
                i++;
            }

            //for the remaining indices till j we will push -1            
            while(i<j && i+k<=nums.size()) {
                ans.push_back(-1);
                i++;
            }
            flag=true;
            j++;

        }
        return ans;     
    }
};