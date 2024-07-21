class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        // Store the topologically sorted sequences.
        vector<int> orderRows = topoSort(rowConditions, k);
        vector<int> orderColumns = topoSort(colConditions, k);

        // If no topological sort exists, return empty array.
        if (orderRows.empty() or orderColumns.empty()) return {};

        vector<vector<int>> matrix(k, vector<int>(k, 0));
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                if (orderRows[i] == orderColumns[j]) {
                    matrix[i][j] = orderRows[i];
                }
            }
        }
        return matrix;
    }

private:
    vector<int> topoSort(vector<vector<int>>& edges, int n) {
        vector<vector<int>> adj(n + 1);
        vector<int> order;
        // 0: not visited, 1: visiting, 2: visited
        vector<int> visited(n + 1, 0);
        bool hasCycle = false;

        // Build adjacency list
        for (auto& x : edges) {
            adj[x[0]].push_back(x[1]);
        }

        // Perform DFS for each node
        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, order, hasCycle);
                // Return empty if cycle detected
                if (hasCycle) return {};
            }
        }
        // Reverse to get the correct order
        reverse(order.begin(), order.end());
        return order;
    }

    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited,
             vector<int>& order, bool& hasCycle) {
        visited[node] = 1;  // Mark node as visiting
        for (int neighbor : adj[node]) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adj, visited, order, hasCycle);
                // Early exit if a cycle is detected
                if (hasCycle) return;
            } else if (visited[neighbor] == 1) {
                // Cycle detected
                hasCycle = true;
                return;
            }
        }
        // Mark node as visited
        visited[node] = 2;
        // Add node to the order
        order.push_back(node);
    }
};