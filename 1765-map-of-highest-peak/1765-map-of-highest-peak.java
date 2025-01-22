class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int m = isWater.length, n = isWater[0].length;
        int[][] height = new int[m][n];
        Queue<int[]> q = new LinkedList<>();
        
        // Initialize water cells
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                height[i][j] = -1;
                if(isWater[i][j] == 1) {
                    height[i][j] = 0;
                    q.offer(new int[]{i, j});
                }
            }
        }
        
        // BFS directions
        int[][] dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // BFS from water to land
        while(!q.isEmpty()) {
            int[] curr = q.poll();
            int x = curr[0], y = curr[1];
            for(int[] dir : dirs) {
                int nx = x + dir[0], ny = y + dir[1];
                if(nx >= 0 && nx < m && ny >= 0 && ny < n && height[nx][ny] == -1) {
                    height[nx][ny] = height[x][y] + 1;
                    q.offer(new int[]{nx, ny});
                }
            }
        }
        return height;
    }
}