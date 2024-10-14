class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        long long score=0;
        for(int i=0; i<k; i++){
            pop_heap(nums.begin(), nums.end());
            int x=nums.back();
            score+=x;
            if (x==1){
                score+=(k-1-i);
                break;
            }
            nums.back()=(x+2)/3;
            push_heap(nums.begin(), nums.end());
        }
        return score;
    }
};