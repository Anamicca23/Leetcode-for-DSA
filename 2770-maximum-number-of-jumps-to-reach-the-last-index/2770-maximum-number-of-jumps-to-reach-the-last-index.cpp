class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dist(n, -1);
        dist[0] = 0;
        for(int i = 0; i < n; i++) {
            if(dist[i] == -1) continue; 
            for(int j = i + 1; j < n; j++) {
                int val = nums[j] - nums[i];
                if(val >= -target && val <= target) {
                    if(dist[j] == -1) {
                        dist[j] = dist[i] + 1;
                    }
                    else if(dist[j] < dist[i] + 1) {
                        dist[j] = dist[i] + 1;
                    }
                }
            }
        }
        return dist[n - 1];
    }
};