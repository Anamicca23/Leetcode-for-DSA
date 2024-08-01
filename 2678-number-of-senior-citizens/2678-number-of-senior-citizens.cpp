class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for (auto s : details) {
            int age = stoi(s.substr(11, 2));
            if (age > 60) cnt++;
        }
        return cnt;
    }
};