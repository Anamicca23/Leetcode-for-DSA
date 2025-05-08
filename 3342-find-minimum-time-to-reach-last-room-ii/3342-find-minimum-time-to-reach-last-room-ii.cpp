using namespace std;

struct Pair {
    int steps, i, j, move;
    Pair(int steps, int i, int j, int move) : steps(steps), i(i), j(j), move(move) {}
    bool operator>(const Pair& other) const {
        return steps > other.steps;
    }
};

class Solution {
public:
    static int minTimeToReach(vector<vector<int>>& moveTime) {
        int r = moveTime.size(), c = moveTime[0].size();
        vector<vector<int>> minimumTime(r, vector<int>(c, INT_MAX));
        priority_queue<Pair, vector<Pair>, greater<Pair>> pq;

        pq.emplace(-1, 0, 0, 1);
        minimumTime[0][0] = 0;

        while (!pq.empty()) {
            Pair top = pq.top(); pq.pop();
            int i = top.i, j = top.j, move = top.move, nextStep = top.steps;

            if (i + 1 < r) update(i + 1, j, pq, nextStep, moveTime, minimumTime, move);
            if (i - 1 >= 0) update(i - 1, j, pq, nextStep, moveTime, minimumTime, move);
            if (j + 1 < c) update(i, j + 1, pq, nextStep, moveTime, minimumTime, move);
            if (j - 1 >= 0) update(i, j - 1, pq, nextStep, moveTime, minimumTime, move);

            if (minimumTime[r - 1][c - 1] != INT_MAX)
                return minimumTime[r - 1][c - 1];
        }
        return -1;
    }

private:
    static void update(int i, int j, priority_queue<Pair, vector<Pair>, greater<Pair>>& pq,int nextStep,vector<vector<int>>& moveTime,vector<vector<int>>& minimumTime,int move) {
        nextStep = move + max(nextStep, moveTime[i][j]);
        if (minimumTime[i][j] > nextStep) {
            pq.emplace(nextStep, i, j, move == 1 ? 2 : 1);
            minimumTime[i][j] = nextStep;
        }
    }
};