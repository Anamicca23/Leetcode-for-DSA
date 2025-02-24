static auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob,
                           vector<int>& amount) {
        auto n = size(amount);
        auto adj = vector<vector<int>>(n);
        for (const auto& edge : edges) {
            auto [u, v] = make_pair(edge.front(), edge.back());
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        auto q = vector<pair<int, int>>{{0, 0}};
        auto next_q = vector<pair<int, int>>{};
        auto visited = vector<bool>(n);
        auto bob_route = find_bob_route(bob, adj);
        auto bob_it = begin(bob_route);
        auto end_bob_route = end(bob_route);
        auto max_income = numeric_limits<int>::min();
        while (!empty(q)) {
            for (auto [u, income] : q) {
                if (bob_it != end_bob_route && u == *bob_it) {
                    income += amount[u] >> 1;
                } else {
                    income += amount[u];
                }
                if (u && size(adj[u]) == 1) {
                    if (income > max_income)
                        max_income = income;
                } else {
                    for (auto j : adj[u]) {
                        if (visited[j])
                            continue;
                        next_q.emplace_back(j, income);
                    }
                }
                visited[u] = true;
            }
            swap(q, next_q);
            next_q.clear();
            if (bob_it != end_bob_route)
                amount[*bob_it++] = 0;
        }
        return max_income;
    }

private:
    vector<int> find_bob_route(int bob, const vector<vector<int>>& adj) {
        auto parent = vector<int>(size(adj), -1);
        parent[bob] = numeric_limits<int>::max();
        auto q = vector<int>{bob};
        auto next_q = vector<int>{};
        while (true) {
            for (auto u : q) {
                for (auto v : adj[u]) {
                    if (v == 0) {
                        auto backtrace = vector<int>{0, u};
                        while (backtrace.back() != bob) {
                            backtrace.push_back(parent[backtrace.back()]);
                        }
                        ranges::reverse(backtrace);
                        return backtrace;
                    } else if (parent[v] < 0) {
                        parent[v] = u;
                        next_q.push_back(v);
                    }
                }
            }
            swap(q, next_q);
            next_q.clear();
        }
    }
};

