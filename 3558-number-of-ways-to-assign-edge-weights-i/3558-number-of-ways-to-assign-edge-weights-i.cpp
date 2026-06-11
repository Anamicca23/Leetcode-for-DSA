class Solution {
    static constexpr int mod = 1000000007;

    long long pow(long long base, int exp) {
        long long res = 1;

        while (exp) {
            if (exp & 1)
                res = res * base % mod;

            base = base * base % mod;
            exp >>= 1;
        }

        return res;
    }

public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int size = edges.size() + 1;
        vector<vector<int>> arr(size + 1);

        for (auto& e : edges) {
            arr[e[0]].push_back(e[1]);
            arr[e[1]].push_back(e[0]);
        }

        auto dfs = [&](this auto&& dfs, int node, int prev) -> int {
            int res = 0;

            for (auto& x : arr[node])
                if (x != prev)
                    res = max(res, dfs(x, node) + 1);

            return res;
        };

        return pow(2, dfs(1, 0) - 1);
    }
};