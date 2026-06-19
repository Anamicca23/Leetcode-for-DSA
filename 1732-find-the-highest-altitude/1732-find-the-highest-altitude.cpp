class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_height = 0;
        int curr_height=0;
        for(int i=0;i<gain.size();i++){
            curr_height += gain[i];
            if(curr_height> max_height) max_height = curr_height;
        }
        return max_height;
    }
};