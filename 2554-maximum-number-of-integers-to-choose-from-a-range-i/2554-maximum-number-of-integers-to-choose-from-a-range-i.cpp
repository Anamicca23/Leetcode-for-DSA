class Solution {
public:
    static int maxCount(vector<int>& banned, int n, int maxSum) {
        banned.push_back(n+1);// make code easier
        sort(banned.begin(), banned.end());
        const int m=banned.size();
        int prev=0, remain=maxSum, cnt=0;
        for(int x: banned){
            if (x>n+1) break;
            if (x==prev) continue;
            int d=x-prev-1;
            int sum=(prev+x)*d/2;// arithmetic progression
            if (sum<=remain){
                cnt+=d;
                remain-=sum;
            }
            else{
                // Use quadratic formula to find largest y such that sum<=remain
                int y=(-1+sqrt(1+4*((prev+1)*prev+2*remain)))/2.0;
                cnt+=y-prev;
                break;
            }
            prev=x;
        }
        return cnt;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();