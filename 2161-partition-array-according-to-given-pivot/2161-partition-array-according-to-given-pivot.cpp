class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        int c = 0;

        for (int x : nums) 
            if (x < pivot) res.push_back(x);
            else if (x == pivot) c++;

        while (c--) res.push_back(pivot);

        for (int x : nums) 
            if (x > pivot) res.push_back(x);

        return res;
    }
};
