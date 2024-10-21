class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> seen;
        int maxCount = 0;
        backtrack(s, 0, seen, 0, maxCount);
        return maxCount;
    }

private:
    void backtrack(const string& s, int start, unordered_set<string>& seen,
                   int count, int& maxCount) {
        // Prune: If the current count plus remaining characters can't exceed
        // maxCount, return
        if (count + (s.size() - start) <= maxCount) return;

        // Base case: If we reach the end of the string, update maxCount
        if (start == s.size()) {
            maxCount = max(maxCount, count);
            return;
        }

        // Try every possible substring starting from 'start'
        for (int end = start + 1; end <= s.size(); ++end) {
            string substring = s.substr(start, end - start);
            // If the substring is unique
            if (seen.find(substring) == seen.end()) {
                // Add the substring to the seen set
                seen.insert(substring);
                // Recursively count unique substrings from the next position
                backtrack(s, end, seen, count + 1, maxCount);
                // Backtrack: remove the substring from the seen set
                seen.erase(substring);
            }
        }
    }
};