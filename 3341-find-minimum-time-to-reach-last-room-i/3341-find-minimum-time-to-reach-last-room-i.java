class Solution {
    public int minTimeToReach(int[][] A) {

        //Dijkstra Algorithm
        //TC = O(n*m(log(n*m))) log for Heap
        //SC = O(n*m)

        int n = A.length;
        int m = A[0].length;

        int[][] distance = new int[n][m];
        boolean[][] visited = new boolean[n][m];

        for(int[] row : distance)
            Arrays.fill(row, Integer.MAX_VALUE);   

        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0]-b[0]);
        pq.add(new int[]{0, 0, 0});
        visited[0][0] = true;

        while(!pq.isEmpty()) {

            int time = pq.peek()[0];
            int row = pq.peek()[1];
            int col = pq.peek()[2];
            pq.remove();

            if(time >= distance[row][col])
                continue;

            if(row == n-1 && col == m-1)
                return time;

            distance[row][col] = time;    
            int[][] directions = {{0,-1},{0,1},{-1,0},{1,0}};
            for(int[] direction : directions) {

                int r = row + direction[0];
                int c = col + direction[1];

                if(r >= 0 && r < n && c >= 0 && c < m && !visited[r][c]) {
                    visited[r][c] = true;
                    pq.add(new int[]{Math.max(A[r][c], time) + 1, r, c});
                }   
            }
        }
        return -1;
    }
}