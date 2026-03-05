class Solution {
public:
    
    int minOperations(string s) {
        int cost1 = 0;
        int cost2 = 0;
        char first = '0';
        char second = '1';
        int n = s.size();
        for(int i = 0; i < n; i++){
            cost1 += s[i] != first;
            cost2 += s[i] != second;
            first = first == '0'? '1' : '0';
            second = second == '0'? '1' : '0';
        }
        return min(cost1, cost2);
    }
};