class Solution {
public:
    class DSU{

        vector<int> parent;
        vector<int> rank;

        public:
        DSU(int n){
            parent.resize(n);
            rank.resize(n);

            for(int i = 0; i < n; i++){
                parent[i] = i;
            }
        }

        int findPar(int u){

            if(parent[u] != u){
                parent[u] = findPar(parent[u]);
            }

            return parent[u];
        }

        void unionByRank(int u , int v){

            int par_u = findPar(u);
            int par_v = findPar(v);

            if(par_u == par_v) return;

            if(rank[par_u] < rank[par_v]){
                parent[par_u] = par_v;
            }else if(rank[par_u] < rank[par_v]){
                parent[par_v] = par_u;
            }else{
                parent[par_u] = par_v;
                rank[par_u]++;
            }
        }

        void unionByLex(int u, int v){

            int par_u = findPar(u);
            int par_v = findPar(v);

            if(par_u == par_v) return;

            if(par_u > par_v){
                parent[par_u] = par_v;
            }else{
                parent[par_v] = par_u;
            }
        }
    };
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        

        int n = s1.size();

        vector<pair<int, int>> vp;

        for(int i = 0; i < n; i++){

            pair<int, int> temp;
            
            int c1 = s1[i] - 'a';
            int c2 = s2[i] - 'a';

            if(c1 != c2){
                if(c1 > c2) temp = {c2, c1};
                else temp = {c1, c2};
                vp.push_back(temp);
            }
        }

        sort(vp.begin(), vp.end());

        DSU dsu = DSU(26);

        for(auto &pr : vp){
            
            int u = pr.first;
            int v = pr.second;

            if(dsu.findPar(u) != dsu.findPar(v)){
                dsu.unionByLex(u, v);
            }
        } 

        for(int i = 0; i < baseStr.size(); i++){

            int k = (baseStr[i] - 'a');

            int par = dsu.findPar(k);
            baseStr[i] = par + 'a';
        }

        return baseStr;
    }
};