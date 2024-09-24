class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for (int val : arr1) while (prefixes.insert(val).second && (val /= 10));

        int longestPrefix = 0;
        for (int val : arr2) {
            while (!prefixes.count(val) && (val /= 10));
            if (val > 0) longestPrefix = max(longestPrefix, (int)log10(val) + 1);
        }
        return longestPrefix;
    }
};
