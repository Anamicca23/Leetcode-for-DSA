class Solution {
public:
    static int numberOfAlternatingGroups(vector<int>& colors, int k) {
        const int n=colors.size(), sz=n+k-1;
        int ans=0, alt=1, prev=colors[0];
        for(int i=1; i<sz; i++){
            alt=(prev==colors[i%n])?1:alt+1;
            if (alt>=k) ans++;
            prev=colors[i%n];
        }
        return  ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();