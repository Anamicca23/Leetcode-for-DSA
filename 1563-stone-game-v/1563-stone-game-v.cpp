class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> sum(n + 1);
        partial_sum(stoneValue.begin(), stoneValue.end(), sum.begin() + 1);
        vector<int> f(n + 1);
        vector suf_max(n + 1, vector<int>(n + 1, INT_MIN));

        for (int i = n - 1; i >= 0; i--) {
            suf_max[i][i + 1] = -sum[i];
            int pre_max = 0;
            int k = i + 1;
            for (int j = i + 2; j <= n; j++) {
                while (sum[k] - sum[i] <= sum[j] - sum[k]) {
                    pre_max = max(pre_max, f[k] + sum[k]);
                    k++;
                }
                int q = sum[k - 1] - sum[i] == sum[j] - sum[k - 1] ? k - 1 : k;
                f[j] = max(pre_max - sum[i], suf_max[q][j] + sum[j]);
                suf_max[i][j] = max(suf_max[i + 1][j], f[j] - sum[i]);
            }
        }

        return f[n];
    }
};