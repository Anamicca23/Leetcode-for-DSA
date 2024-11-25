vector<vector<char>> adj = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
int shift[6] = {15, 12, 9, 6, 3, 0};

class Solution {
public:
    static int slidingPuzzle(vector<vector<int>>& board) {
        int target = 0123450, start = 0, pos0 = -1;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++) {
                int idx = i * 3 + j;
                start += (board[i][j] << shift[idx]);
                if (board[i][j] == 0) pos0 = idx;
            }
        if (start == target) return 0;

        const int N = 0543211;
        bitset<N> viz;
        queue<pair<int, char>> q;
        q.emplace(start, pos0);

        for (int moves = 0; !q.empty(); moves++) {
            int sz = q.size();
            while (sz--) {
                auto [state, p0] = q.front();
                q.pop();
                if (state == target) return moves;
                for (char p : adj[p0]) {
                    int s = state, B = shift[p], x = (s >> B) & 7;
                    s += -(x << B) + (x << shift[p0]);
                    if (viz[s]) continue;
                    q.emplace(s, p), viz[s] = 1;
                }
            }
        }
        return -1;
    }
};
