class Solution {
public:
    static int countBinarySubstrings(string& s) {
        const int n=s.size();
        int prev=0, cur=1, cnt=0;
        for(int i=1; i<n; i++){
            if (s[i]==s[i-1]) cur++;
            else{
                cnt+=min(cur, prev);
                prev=exchange(cur, 1);
            }
        }
        cnt+=min(cur, prev);
        return cnt;
    }
};