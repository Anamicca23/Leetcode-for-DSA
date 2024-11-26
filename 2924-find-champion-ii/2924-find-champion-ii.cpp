class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>freq(n);
        for(auto&x:edges){int e = x[1];freq[e]++;}
        int champ =-1, cnt=0;
        for(int i=0; i<freq.size();i++){
            if(freq[i]==0){
                champ = i; cnt++;
                if(cnt>1)return -1;
            }
        }
        return champ;
    }
};