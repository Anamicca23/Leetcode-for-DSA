class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = s.size();
        sort(g.rbegin(), g.rend());
        sort(s.rbegin(), s.rend());
        int curr=0, total =0;
        for(int i =0; i<g.size(); i++){
            if(curr<n and g[i]<= s[curr]){
                curr++;
                total++;
            }
        }
        return total;
    }
};