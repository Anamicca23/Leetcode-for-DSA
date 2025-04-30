class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for (int i : nums) {
            string s = to_string(i);
            if (s.size() % 2 == 0) count++;
        }
        return count;
    }
};