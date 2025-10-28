class Solution {
    public int countValidSelections(int[] nums) {
        int total = 0, ls = 0, cases = 0;
        for (int num : nums) total += num;

        for (int num : nums) {
            int rs = total - ls - num;
            if (num == 0) {
                if (ls == rs) {
                    cases += 2;
                } else if (ls == rs - 1 || ls - 1 == rs) {
                    cases += 1;
                }
            }
            ls += num;
        }
        return cases;
    }
}