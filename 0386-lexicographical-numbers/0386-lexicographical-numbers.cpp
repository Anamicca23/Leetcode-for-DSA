class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for (int num = 1; ans.size() < n;) {
            ans.push_back(num);
            if (num * 10 <= n) num *= 10;
            else {
                if (num % 10 == 9 || num + 1 > n) 
                while ((num /= 10) % 10 == 9);
                num++;
            }
        }
        return ans;
    }
};
