class Solution {
public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int rows = moveTime.size();
        int cols = moveTime[0].size();

        int** visit = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            visit[i] = new int[cols];
            for (int j = 0; j < cols; ++j) {
                visit[i][j] = -1;
            }
        }

        const int MAXQ = rows * cols * 10;
        int q[MAXQ][2], front = 0, back = 0;

        q[back][0] = 0;
        q[back++][1] = 0;
        visit[0][0] = 0;

        while (front < back) {
            int x = q[front][0];
            int y = q[front++][1];

            for (int d = 0; d < 4; ++d) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || nx >= rows || ny < 0 || ny >= cols) continue;

                int nt = max(visit[x][y], moveTime[nx][ny]) + 1;

                if (visit[nx][ny] == -1 || nt < visit[nx][ny]) {
                    visit[nx][ny] = nt;
                    q[back][0] = nx;
                    q[back++][1] = ny;
                }
            }
        }

        int result = visit[rows - 1][cols - 1];
        return result;
    }
};