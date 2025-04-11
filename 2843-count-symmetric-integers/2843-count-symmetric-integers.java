class Solution {
    public int countSymmetricIntegers(int low, int high) {
        int count = 0;
        for (int i = low; i <= high; i++) {
            String s = Integer.toString(i);
            if (s.length() % 2 == 0 && 
                sum(s.substring(0, s.length() / 2)) == sum(s.substring(s.length() / 2))) {
                count++;
            }
        }
        return count;
    }
    
    private int sum(String str) {
        int sum = 0;
        for (int i = 0; i < str.length(); i++) {
            sum += str.charAt(i) - '0';  
        }
        return sum;
    }
}