class Solution {
public:
    int components;
    vector<int> parent, size;

    int Union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return 0;

        components--;
        if(size[pu] > size[pv]){
            size[pu] += size[pv];
            parent[pv] = pu;
        }
        else{
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        return 1;
    }

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {
        components = n;
        parent.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        vector<vector<int>> must, flex;

        for(auto &it : edges){
            if(it[3] == 1) must.push_back(it);
            else flex.push_back(it);
        }

        int mini = INT_MAX;

        for(auto &it : must){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            mini = min(mini, w);

            if(!Union(u, v)){
                return -1;
            }
        }

        sort(flex.begin(), flex.end(), [](vector<int>& a, vector<int>& b){
            return a[2] > b[2];
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto &it : flex){
            int u = it[0];
            int v = it[1];
            int w = it[2];

            if(Union(u, v)){
                pq.push(w);
            }
        }

        while(k-- && !pq.empty()){
            int x = pq.top();
            pq.pop();
            mini = min(mini, 2 * x);
        }

        if(components != 1) return -1;

        if(!pq.empty()){
            return min(mini, pq.top());
        }

        return mini;
    }
};