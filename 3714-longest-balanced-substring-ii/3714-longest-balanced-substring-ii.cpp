using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        int ans = 0;
        ans = max(ans, longestSingle(s));
        ans = max(ans, longestTwo(s, 'a', 'b'));
        ans = max(ans, longestTwo(s, 'a', 'c'));
        ans = max(ans, longestTwo(s, 'b', 'c'));
        ans = max(ans, longestThree(s));
        return ans;
    }
    int longestSingle(const string &s) {
        int maxLen = 0;
        int i = 0, n = s.size();
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            maxLen = max(maxLen, j - i);
            i = j;
        }
        return maxLen;
    }
    int longestTwo(const string &s, char x, char y) {
        int res = 0;
        int i = 0, n = s.size();
        while (i < n) {
            while (i < n && s[i] != x && s[i] != y) i++;

            unordered_map<int, int> pos;
            pos[0] = i - 1;
            int diff = 0;

            while (i < n && (s[i] == x || s[i] == y)) {
                diff += (s[i] == x ? 1 : -1);
                if (pos.count(diff))
                    res = max(res, i - pos[diff]);
                else
                    pos[diff] = i;

                i++;
            }
        }
        return res;
    }

    int longestThree(string s) {
        map<pair<int,int>, int> firstSeen;

        int countA = 0, countB = 0, countC = 0;
        int ans = 0;
        firstSeen[{0, 0}] = -1;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') countA++;
            else if (s[i] == 'b') countB++;
            else countC++;

            int d1 = countA - countB;
            int d2 = countA - countC;

            pair<int,int> state = {d1, d2};

            if (firstSeen.count(state)) {
                ans = max(ans, i - firstSeen[state]);
            } else {
                firstSeen[state] = i;
            }
        }

        return ans;
    }

};