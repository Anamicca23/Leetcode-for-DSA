class Solution {
public:
    #define INF 1e9
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // Approach get the cost of converting a single character to every other character
        int n = original.size();
        vector<vector<long long>> graph(26, vector<long long>(26, INF));
        for(int i = 0; i < n; i++) {
            graph[original[i] - 'a'][changed[i]-'a'] = min(graph[original[i] - 'a'][changed[i]-'a'], (long long)cost[i]);
        }
        // Get the minimum cost using floyd warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if ((graph[k][j] != INF
                            && graph[i][k] != INF) && graph[i][j] > (long long) (graph[i][k] + graph[k][j]))
                        graph[i][j] = (long long)(graph[i][k] + graph[k][j]);
                }
            }
        }
        long long ans = 0;
        for(int i = 0; i < source.length(); i++) {
            int a = source[i] - 'a';
            int b = target[i] - 'a';
            if(a != b) {
                if(graph[a][b] == INF) return -1;
                ans =  (long long) (ans + graph[a][b]);
            }
        }
        return ans;
    }
};