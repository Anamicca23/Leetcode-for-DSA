class Solution {
    public int minimumRecolors(String blocks, int k) {
        int opr=0, n=blocks.length(), ans;
        for(int i=0; i<k; i++){
            if(blocks.charAt(i)=='W') opr++;
        }
        ans=opr;
        for(int i=k; i<n; i++){
            if(blocks.charAt(i-k)!=blocks.charAt(i)){
                if(blocks.charAt(i-k)=='W') opr--;
                else opr++;
            }
            if(ans>opr) {
                ans=opr;
                if(ans==0) return ans;
            }
        }
        return ans;
    }
}