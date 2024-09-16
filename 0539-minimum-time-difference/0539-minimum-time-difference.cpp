class Solution {
public:
    static int findMinDifference(vector<string>& timePoints) {
        const int N=24*60, H=12*60;
        int minX=N, maxX=0;
        bitset<N> seen=0;
        for(string& s: timePoints){
            int x=((s[0]-'0')*10+s[1]-'0')*60+(s[3]-'0')*10+(s[4]-'0');
            if (seen[x]) return 0;
            seen[x]=1;
            minX=min(x, minX);
            maxX=max(x, maxX);
        }
        int diff=N, prev=minX;
        for(int x=minX+1; x<=maxX; x++){
            if (!seen[x]) continue;
            diff=min(diff, x-prev);
            prev=x;
        }
        diff=min(N-(maxX-minX), diff);
        return diff;
    }
};