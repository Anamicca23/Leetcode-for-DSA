class Solution {
    public int countPrimeSetBits(int left, int right) {
        int[] primes = {2,3,5,7,11,13,17,19};
        java.util.Set<Integer> primeSet = new java.util.HashSet<>();
        
        for(int p : primes) {
            primeSet.add(p);
        }
        
        int ans = 0;
        
        for(int num = left; num <= right; num++) {
            int setBits = Integer.bitCount(num);
            
            if(primeSet.contains(setBits)) {
                ans++;
            }
        }
        
        return ans;
    }
}