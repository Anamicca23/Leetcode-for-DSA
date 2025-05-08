class Solution {
   static public int minTimeToReach(int[][] moveTime) {
        int r = moveTime.length, c = moveTime[0].length;
        int[][] minimumTime = new int[r][c];
        for (int[] is : minimumTime) {
            Arrays.fill(is, Integer.MAX_VALUE);
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.steps - b.steps);
        pq.add(new Pair(-1, 0, 0,1));
        minimumTime[0][0] = 0;

        while (!pq.isEmpty()) {
            Pair top = pq.poll();
            int i = top.i, j = top.j,  move = top.move, nextStep = top.steps;
            if (i + 1 < r) update(i + 1, j, pq, nextStep, moveTime, minimumTime, move);
            if (i - 1 >= 0) update(i - 1, j, pq, nextStep, moveTime, minimumTime, move);
            if (j - 1 >= 0) update(i, j - 1, pq, nextStep, moveTime, minimumTime, move);
            if (j + 1 < c)  update(i, j + 1, pq, nextStep, moveTime, minimumTime, move);
            if(minimumTime[r-1][c-1] != Integer.MAX_VALUE) return minimumTime[r-1][c-1];
        }
        return -1;
    }

    static void update(int i, int j, PriorityQueue<Pair> pq, int nextStep, int[][] moveTime, int[][] minimumTime,int move){
        nextStep =  move + Math.max(nextStep, moveTime[i][j]);
        if (minimumTime[i][j] > nextStep) {
            pq.add(new Pair(nextStep, i, j, (move == 1 ? 2 : 1)));
            minimumTime[i][j] = nextStep;
        }
    }

}

class Pair {
    int steps = 0, i = -1, j = -1,move;

    public Pair(int steps, int i, int j,int move) {
        this.steps = steps;
        this.i = i;
        this.j = j;
        this.move = move;
    }
}