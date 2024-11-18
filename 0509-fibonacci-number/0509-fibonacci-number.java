class Solution {
    public int fib(int n) {
        HashMap<Integer,Integer> check = new HashMap<>();
        if(n==0||n==1) return n;
        check.put(0,0);
        check.put(1,1);
        for(int i=2;i<=n;i++){
            int result = check.get(i-1)+check.get(i-2);
            check.put(i,result);
        }
        return check.get(n);
    }
}