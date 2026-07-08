class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int m = queries.size();
        long long MOD = 1e9 + 7;

        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefVal(n + 1, 0);
        vector<int> prefCnt(n + 1, 0);
        vector<long long> power(n + 1, 1);

        for(int i = 1; i <= n; i++){
            power[i] = (power[i - 1] * 10) % MOD;
        }

        for(int i = 0; i < n; i++){
            int d = s[i] - '0';

            prefSum[i + 1] = prefSum[i] + d;
            prefCnt[i + 1] = prefCnt[i] + (d != 0);

            if(d == 0){
                prefVal[i + 1] = prefVal[i];
            }
            else{
                prefVal[i + 1] = (prefVal[i] * 10 + d) % MOD;
            }
        }

        vector<int> result(m);

        for(int i = 0; i < m; i++){
            int l = queries[i][0];
            int r = queries[i][1];

            int len = prefCnt[r + 1] - prefCnt[l];

            long long start = prefVal[l];
            long long end = prefVal[r + 1];

            long long x = (end - (start * power[len]) % MOD + MOD) % MOD;
            long long sum = prefSum[r + 1] - prefSum[l];

            result[i] = (x * sum) % MOD;
        }

        return result;
    }
};