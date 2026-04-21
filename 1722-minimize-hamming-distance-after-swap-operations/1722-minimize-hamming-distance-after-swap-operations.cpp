class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int a, int b) { parent[find(a)] = find(b); }

    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (auto& swap : allowedSwaps)
            unite(swap[0], swap[1]);

        unordered_map<int, unordered_map<int, int>> groupFreq;
        for (int i = 0; i < n; i++)
            groupFreq[find(i)][source[i]]++;

        int hammingDistance = 0;
        for (int i = 0; i < n; i++) {
            int root = find(i);
            auto& freq = groupFreq[root];
            if (freq.count(target[i]) && freq[target[i]] > 0)
                freq[target[i]]--;
            else
                hammingDistance++;
        }

        return hammingDistance;
    }
};