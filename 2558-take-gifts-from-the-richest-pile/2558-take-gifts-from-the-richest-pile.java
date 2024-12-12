class Solution {
    public long pickGifts(int[] gifts, int k) {
        int n=gifts.length;
        PriorityQueue<Integer> pq=new PriorityQueue<>((a,b)->b-a);
        long sum=0;
        
        for(int i=0; i<n; i++){
            sum+=gifts[i];
            pq.add(gifts[i]);
        }

        for(int i=0; i<k; i++){
            int val=pq.poll();
            sum-=val;
            val=(int)Math.sqrt(val);
            sum+=val;
            pq.add(val);
        }

        return sum;
    }
}