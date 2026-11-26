class Solution {
    public boolean canAliceWin(int n) {
        return (0x61F03F807FC00L >> n & 1) == 1;
    }
}