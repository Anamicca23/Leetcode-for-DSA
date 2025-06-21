using namespace std;

class Solution {
public:
    int minimumDeletions(const string& word, int k) {
        array<int, 26> freq{};
        for (unsigned char c : word)
            ++freq[c - 'a'];

        vector<int> freqList;
        freqList.reserve(26);
        for (int f : freq)
            if (f > 0)
                freqList.push_back(f);

        sort(begin(freqList), end(freqList));

        int n = freqList.size(), total = word.size(), removedLeft = 0,
            inWindowSum = 0, best = INT_MAX, r = 0;

        for (int l = 0; l < n; ++l) {
            int base = freqList[l];
            int limit = base + k;

            while (r < n && freqList[r] <= limit)
                inWindowSum += freqList[r++];

            int rightCount = n - r;
            int rightSum = total - inWindowSum;
            int delRight = rightSum - rightCount * limit;

            best = min(best, removedLeft + delRight);

            total -= freqList[l];
            removedLeft += freqList[l];
            inWindowSum -= freqList[l];
        }

        return best;
    }
};