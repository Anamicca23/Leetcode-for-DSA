class Solution {
public:
    static const int MOD = 1000000007;
    static vector<int> binaryExponent;
    vector<vector<int>> ancestors;
    vector<int> parent;
    vector<int> depth;
    vector<int> ans;
    void dfs(int node, int par, vector<vector<int>>& adj, int depthValue) {
        parent[node] = par;
        depth[node] = depthValue;
        for (int child : adj[node]) {
            if (child == par) continue;
            dfs(child, node, adj, depthValue + 1);
        }
    }
    void buildAncestors(int n) {
        int maxLog = 18; 
        ancestors.assign(maxLog, vector<int>(n + 1));
        for (int node = 1; node <= n; node++) {
            ancestors[0][node] = parent[node];
        }
        for (int jump = 1; jump < maxLog; jump++) {
            for (int node = 1; node <= n; node++) {
                ancestors[jump][node] = ancestors[jump - 1][ancestors[jump - 1][node]];
            }
        }
    }
    int LCA(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }
        int diff = depth[u] - depth[v];
        for (int bit = 0; diff > 0; bit++) {
            if (diff & 1) {
                u = ancestors[bit][u];
            }
            diff >>= 1;
        }
        if (u == v) return u;
        for (int jump = (int)ancestors.size() - 1;
             jump >= 0;
             jump--) {
            if (ancestors[jump][u] !=
                ancestors[jump][v]) {
                u = ancestors[jump][u];
                v = ancestors[jump][v];
            }
        }
        return ancestors[0][u];
    }
    int getPathLength(int u, int v) {
        int lca = LCA(u, v);
        return depth[u] + depth[v] - 2 * depth[lca];
    }
        vector<int> assignEdgeWeights(
        vector<vector<int>>& edges,
        vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        int q = queries.size();
        parent.assign(n + 1, 0);
        depth.assign(n + 1, 0);
        ans.resize(q);
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 1, adj, 0);
        buildAncestors(n);
        for (int i = 0; i < q; i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            int pathLength = getPathLength(u, v);
            ans[i] = binaryExponent[pathLength];
        }
        return ans;
    }
};
vector<int> Solution::binaryExponent = []() {
    vector<int> power(100001);
    long long curr = 1;

    for (int i = 1; i <= 100000; i++) {
        power[i] = curr;
        curr = (curr * 2LL) % Solution::MOD;
    }

    return power;
}();