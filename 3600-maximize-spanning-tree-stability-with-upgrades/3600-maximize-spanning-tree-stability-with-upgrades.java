class Solution {
    int components;
    int[] parent;
    int[] size;
    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
    boolean union(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return false;

        components--;

        if(size[pu] > size[pv]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }

        return true;
    }

    public int maxStability(int n, int[][] edges, int k) {

        components = n;
        parent = new int[n];
        size = new int[n];

        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }

        List<int[]> must = new ArrayList<>();
        List<int[]> flex = new ArrayList<>();

        for(int[] e : edges){
            if(e[3] == 1) must.add(e);
            else flex.add(e);
        }

        int mini = Integer.MAX_VALUE;

        for(int[] e : must){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            mini = Math.min(mini, w);

            if(!union(u,v)) return -1;
        }
        flex.sort((a,b) -> b[2] - a[2]);
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int[] e : flex){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(union(u,v)){
                pq.add(w);
            }
        }
        while(k-- > 0 && !pq.isEmpty()){
            int x = pq.poll();
            mini = Math.min(mini, 2 * x);
        }
        if(components != 1) return -1;
        if(!pq.isEmpty()){
            return Math.min(mini, pq.peek());
        }
        return mini;
    }
}