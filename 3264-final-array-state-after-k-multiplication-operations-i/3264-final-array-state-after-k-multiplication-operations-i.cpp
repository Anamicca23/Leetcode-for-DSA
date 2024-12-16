class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<pair<int, int>> heap(nums.size());
        for (int i = 0; i < nums.size(); i++) 
            heap[i] = {nums[i], i};
        
        make_heap(heap.begin(), heap.end(), greater<>());
        
        while (k--) {
            pop_heap(heap.begin(), heap.end(), greater<>());
            auto [num, idx] = heap.back();
            heap.pop_back();
            nums[idx] = num * multiplier;
            heap.push_back({nums[idx], idx});
            push_heap(heap.begin(), heap.end(), greater<>());
        }
        return nums;
    }
};
