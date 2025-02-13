class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>
        pq(nums.begin(),nums.end());
        int count=0;
        while(pq.top()<k){
            long long min1=pq.top();
            pq.pop();
            long long min2=pq.top();
            pq.pop();
            min1=min1*2+min2;
            pq.push(min1);
            ++count;
        }
        return count;
    }
};