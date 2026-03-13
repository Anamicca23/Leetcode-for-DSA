class Solution {
    public long minNumberOfSeconds(int h, int[] t) {
        PriorityQueue<long[]> pq = new PriorityQueue<>(
            (a, b) -> Long.compare(a[0], b[0])
        );
        for(int i = 0; i < t.length; i++){
            pq.add(new long[]{t[i], i, 1});
        }
        long res = 0;
        while(h > 0){
            long[] cur = pq.poll();
            long tm = cur[0];
            int id = (int)cur[1];
            int x = (int)cur[2];
            res = tm;
            h--;
            if(h > 0){
                long nx = x + 1;
                long nt = (long)t[id] * (nx * (nx + 1) / 2);
                pq.add(new long[]{nt, id, nx});
            }
        }
        return res;
    }
}