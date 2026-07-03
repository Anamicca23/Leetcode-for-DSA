class Solution {
public:
    int n;
    bool find(int limit, unordered_map<int, vector<pair<int,int>>>& adj,
              vector<bool>& online, vector<int>& topoSort, long long k){

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        for(int node : topoSort){
            if(dist[node] == LLONG_MAX) continue;

            for(auto &nxt : adj[node]){
                int nxtNode = nxt.first;
                int cst = nxt.second;
                if(cst < limit) continue;
                if(nxtNode != n-1 && !online[nxtNode]) continue;
                dist[nxtNode] = min(dist[nxtNode], dist[node] + cst);
            }
        }
        return dist[n-1] <= k;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        unordered_map<int, vector<pair<int,int>>> adj;
        vector<int> indegree(n, 0);
        int low = INT_MAX;
        int high = 0;
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int cst = e[2];
            adj[u].push_back({v, cst});
            indegree[v]++;
            low = min(low, cst);
            high = max(high, cst);
        }

        queue<int> q;
        vector<int> topoSort;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topoSort.push_back(node);
            for(auto &ngbr : adj[node]){
                int nxtNode = ngbr.first;
                indegree[nxtNode]--;
                if(indegree[nxtNode] == 0){
                    q.push(nxtNode);
                }
            }
        }
        int res = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(find(mid, adj, online, topoSort, k)){
                res = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return res;
    }
};