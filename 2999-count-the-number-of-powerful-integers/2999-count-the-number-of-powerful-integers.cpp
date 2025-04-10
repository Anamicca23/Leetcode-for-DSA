typedef long long int lli;
const lli N = 50;
lli dp[N][2];
class Solution {
public:
	lli Dfs(lli idx, bool tight, lli limit, string& now, string& s) {
		lli ret = 0;
        // cout << idx << " " << tight << " " << limit << " " << now << " " << s << endl;
		if (idx >= now.size()) return 1;
		if (dp[idx][tight] != -1) return dp[idx][tight];
        if(now.size() < s.size()) return 0;
		lli j = idx - (now.size() - s.size());
		lli now_val = now[idx] - '0';
        // cout << idx << " " << j << endl;
		if (j >= 0) {
            // cout << "YES" << endl;    
			lli s_val = s[j] - '0';
			// Suffix
			if ((tight && (now_val < s_val)) || (limit < s_val)) {
                // cout << "BAD" << endl;
				ret = 0;

			} else {
				ret = Dfs(idx + 1, tight && now_val == s_val, limit, now, s);
			}
		} else {
			// Non Suffix
			for (int i = 0; i <= (tight ? min(limit, now_val) : min((lli)9, limit)); i++) {
				ret += Dfs(idx + 1, tight && i == now_val, limit, now, s);
			}

		}
		return dp[idx][tight] = ret;
	}
	lli Calculate(lli value, string& suffix_str, lli limit) {
		memset(dp, -1, sizeof dp);
		string s = to_string(value);
		return Dfs(0, 1, limit, s, suffix_str);
	}
	long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
		lli ret = 0;
		start--;
		ret = -Calculate(start, s, limit);
		ret += Calculate(finish, s, limit);
		return ret;
	}
};