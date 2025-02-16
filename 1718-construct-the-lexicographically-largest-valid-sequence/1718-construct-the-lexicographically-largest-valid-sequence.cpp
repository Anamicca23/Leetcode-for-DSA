class Solution {
public:
    int n, az;
    bitset<21> viz = 0;
    vector<int> ans;
    
    bool dfs(int pos) {
        if (pos==az) return viz.count()==n;  // Base case: all numbers used
        if (ans[pos]!= 0) return dfs(pos+1);  // Skip if already filled
        
        for (int j=n; j>= 1; j--) {  // larger first
            if (viz[j]) continue;  // If j is used, skip
            int next_pos=(j>1)?pos+j:pos;  // should put j
            
            if (next_pos>=az || ans[next_pos]!=0) continue;  // Ensure valid placement
            
            ans[pos]=ans[next_pos]= j;  // Place j
            viz[j]=1;
            
            if (dfs(pos+1)) return 1;  // Recurse
            
            // Backtrack
            ans[pos]=ans[next_pos]=viz[j]=0;
        }
        return 0;
    }

    vector<int> constructDistancedSequence(int n) {
        this->n=n;
        az=2*n-1;
        ans.assign(az, 0);
        dfs(0);
        return ans;
    }
};