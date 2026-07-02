class Solution {
    static class Pair{
        int row;
        int col;
        int health;
        Pair(int row,int col,int health){
            this.row=row;
            this.col=col;
            this.health=health;
        }
    }
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int n=grid.size(),m=grid.get(0).size();
        Queue<Pair>queue=new LinkedList<>();
        int[][]visited=new int[n][m];
        for(int[]row:visited)Arrays.fill(row,-1);
        health-=grid.get(0).get(0);
        visited[0][0]=health;
        queue.add(new Pair(0,0,health));
        int[]allowdRow={0,-1,1,0};
        int[]allowedCol={-1,0,0,1};
        while(!queue.isEmpty()){
            Pair cur=queue.poll();
            if(cur.row==n-1&&cur.col==m-1){
                return true;
            }
            for(int i=0;i<4;i++){
                int newRow=cur.row+allowdRow[i];
                int newCol=cur.col+allowedCol[i];
                if(newRow>=0&&newRow<n&&newCol>=0&&newCol<m){
                    int newHealth=cur.health-grid.get(newRow).get(newCol);
                    if(newHealth>0&&newHealth>visited[newRow][newCol]){
                        visited[newRow][newCol]=newHealth;
                        queue.offer(new Pair(newRow,newCol,newHealth));
                    }
                }
            }
        }
        return false;
    }
}