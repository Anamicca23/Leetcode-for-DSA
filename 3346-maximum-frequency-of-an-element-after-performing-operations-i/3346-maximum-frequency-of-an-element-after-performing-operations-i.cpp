class Solution {
public:
    static int maxFrequency(vector<int>& nums, int k, int numOperations) {
        static constexpr int N=1e5+2;
        int freq[N]={0}, sweep[N]={0}, mm=N, MM=0;
        for(int x: nums){
            freq[x]++;
            const int x0=max(1, x-k), xN=min(x+k+1, N-1);
            sweep[x0]++;
            sweep[xN]--;
            mm=min(mm, x0);
            MM=max(MM, xN);
        }
        int ans=0, cnt=0;
        for (int x=mm; x<=MM; x++){
            cnt+=sweep[x];
            ans=max(ans, freq[x]+min(cnt-freq[x], numOperations));
        }
        return ans;
    }
};