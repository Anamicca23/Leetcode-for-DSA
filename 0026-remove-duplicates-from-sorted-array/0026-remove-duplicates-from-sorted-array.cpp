class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //Array
        int modidx =1;
        for(int i = 0; i< nums.size()-1;i++){
            //if value at index is not equal to next value
            if(nums[i] != nums[i+1]){
                //modifing value of that index with next value by which we remove duplicate
                 nums[modidx++]=nums[i+1]; 
            }
        }
        //returning length of that expected array;
        return modidx;
    }
};