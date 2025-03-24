class Solution {
    public int[][] merge(int[][] A) {
        if(A.length <= 1) return A;

        Arrays.sort(A, (i1, i2) -> Integer.compare(i1[0], i2[0]));

        List<int[]> res = new ArrayList<>();
        int[] Prev = A[0];
        res.add(Prev);
        for(int[] Curr : A){
            if(Curr[0] <= Prev[1]){
                Prev[1] = Math.max(Prev[1], Curr[1]);
            }
            else {                             
                res.add(Curr);
                Prev = Curr;
            }
        }
        return res.toArray(new int [res.size()][]);
    }
    
    public int countDays(int days, int[][] A) {
        int[][] newA = merge(A);
        for(int[] interval : newA) {
            days -= (interval[1] - interval[0] + 1);
        }
        return days;
    }
}