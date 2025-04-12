#include <array>
#include <string>
#include <unordered_set>
#include <ranges>

using namespace std;

constexpr auto fact = [] {
  array<long long, 11> f{1, 1};
  for (int i = 2; i < 11; ++i) f[i] = i * f[i - 1];
  return f;
}();

long long perm_index(int n, int k, const array<int, 10>& cnt) {
  long long idx = n | (k << 4);
  for (int i = 0; i < 10; ++i) idx |= static_cast<long long>(cnt[i]) << (4 * (i + 2));
  return idx;
}

void count_perms(string& pre, array<array<long long, 10>, 11>& res, unordered_set<long long>& seen) {
  if (pre.empty()) {
    for (char c = '1'; c <= '9'; ++c) {
      pre.push_back(c);
      count_perms(pre, res, seen);
      pre.pop_back();
    }
  } else {
    for (int cut = 0; cut < 2; ++cut) {
      string suf = pre.substr(0, pre.size() - cut);
      reverse(suf.begin(), suf.end());
      string pal = pre + suf;

      array<int, 10> cnt{};
      for (char d : pal) ++cnt[d - '0'];
      int n = pal.size();

      long long perms = fact[n];
      for (int c : cnt) if (c > 1) perms /= fact[c];
      if (cnt[0]) perms -= perms * cnt[0] / n;

      long long val = stoll(pal);
      for (int k = 1; k < 10; ++k) {
        long long idx = perm_index(n, k, cnt);
        if (val % k == 0 && !seen.contains(idx)) {
          res[n][k] += perms;
          seen.insert(idx);
        }
      }
    }
    if (pre.size() < 5) {
      for (char c = '0'; c <= '9'; ++c) {
        pre.push_back(c);
        count_perms(pre, res, seen);
        pre.pop_back();
      }
    }
  }
}

const array<array<long long, 10>, 11> solutions = [] {
  array<array<long long, 10>, 11> res{};
  unordered_set<long long> seen;
  string prefix;
  count_perms(prefix, res, seen);
  return res;
}();

class Solution {
public:
  long long countGoodIntegers(int n, int k) {
    return solutions[n][k];
  }
};
