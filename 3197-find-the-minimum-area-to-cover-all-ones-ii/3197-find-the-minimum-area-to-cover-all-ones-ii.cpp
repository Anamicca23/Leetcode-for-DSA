class Solution {
public:
    
    vector<vector<int>> row_sfx, col_sfx;

    int get_row_count(int i, int l, int r) {
        return row_sfx[i][l] - row_sfx[i][r + 1];
    }

    int get_col_count(int j, int t, int b) {
        return col_sfx[j][t] - col_sfx[j][b + 1];
    }

    int f1(int si, int ei, int sj, int ej) 
    { // start i, end i, start j, end j;
        int const n = row_sfx.size(), m = col_sfx.size();

        while (si < ei && !get_row_count(si, sj, ej)) si++;
        while (ei > si && !get_row_count(ei, sj, ej)) ei--;
        while (sj < ej && !get_col_count(sj, si, ei)) sj++;
        while (ej > sj && !get_col_count(ej, si, ei)) ej--;

        int l = ej - sj + 1, h = ei - si + 1;
        return max(l, 0) * max(h, 0); 
    } // min area to cover all ones in range with a single rect;

    int f2(int si, int ei, int sj, int ej)
    { // min area to cover all ones in range with 2 rect;
        int res = max(0, (ei - si + 1)) * max(0, (ej - sj + 1));

        for (int i = si; i <= ei - 1; i++)
        { // row partition, [si, i] U [i + 1, ei];
            int curr = f1(si, i, sj, ej) + f1(i + 1, ei, sj, ej);
            res = min(res, curr);
        }

        for (int j = sj; j <= ej - 1; j++)
        { // col partiion, [sj, j] U [j + 1, ej];
            int curr = f1(si, ei, sj, j) + f1(si, ei, j + 1, ej);
            res = min(res, curr);
        }

        return res;
    }

    int minimumSum(vector<vector<int>>& grid)
    {
        int const n = grid.size(), m = grid[0].size();
        row_sfx = vector<vector<int>>(n, vector<int>(m + 1)), col_sfx = vector<vector<int>>(m, vector<int>(n + 1));

        for (int i = 0; i <= n - 1; i++) {
            for (int j = m - 1; j >= 0; j--) row_sfx[i][j] = grid[i][j] + row_sfx[i][j + 1];
        }
        for (int j = 0; j <= m - 1; j++) {
            for (int i = n - 1; i >= 0; i--) col_sfx[j][i] = grid[i][j] + col_sfx[j][i + 1];
        }
    
        int ans = n * m;
        for (int i = 0; i <= n - 2; i++)
        { // row partition, [0, i] U [i + 1, n - 1]
            int c12 = f1(0, i, 0, m - 1) + f2(i + 1, n - 1, 0, m - 1);
            int c21 = f2(0, i, 0, m - 1) + f1(i + 1, n - 1, 0, m - 1);

            int c = min(c12, c21);
            ans = min(ans, c);
        }

        for (int j = 0; j <= m - 2; j++)
        { // row partition, [0, i] U [i + 1, n - 1]
            int c12 = f1(0, n - 1, 0, j) + f2(0, n - 1, j + 1, m - 1);
            int c21 = f2(0, n - 1, 0, j) + f1(0, n - 1, j + 1, m - 1);

            int c = min(c12, c21);
            ans = min(ans, c);
        }

        return ans;    
    }
};