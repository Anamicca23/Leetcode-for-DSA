static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

constexpr unsigned int max_weight = (1 << bit_width(100'000u)) - 1u;

struct DisjointSet {
  DisjointSet* parent = this;
  unsigned int weight = max_weight;
};

DisjointSet& find(DisjointSet& x) {
  auto px = &x;
  while (px != px->parent) {
    tie(px, px->parent) = make_tuple(px->parent, px->parent->parent);
  }
  return *px;
}

void unify(DisjointSet& x, DisjointSet& y, unsigned int weight) {
  auto px = &find(x);
  auto py = &find(y);
  if (px == py) {
    if (px->weight) px->weight &= weight;
    return;
  }
  if (py->weight < px->weight) swap(px, py);
  if (px->weight) px->weight &= py->weight & weight;
  py->parent = px;
}

class Solution {
public:
  vector<int> minimumCost(int n, const vector<vector<int>>& edges, const vector<vector<int>>& query) {
    auto forest = vector<DisjointSet>(n);
    for (auto& edge : edges) {
      auto [u, v, w] = make_tuple(edge[0], edge[1], edge[2]);
      unify(find(forest[u]), find(forest[v]), w);
    }

    auto ans = vector<int>{};
    ans.reserve(size(query));
    for (auto& q : query) {
      auto [u, v] = make_pair(q[0], q[1]);
      const auto& node_u = find(forest[u]);
      const auto& node_v = find(forest[v]);
      ans.push_back(&node_u == &node_v ? node_u.weight : -1);
    }
    return ans;
  }
};