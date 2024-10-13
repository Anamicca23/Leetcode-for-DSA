class Solution {
public:
    vector<int> smallestRange(const vector<vector<int>>& nums) {
        vector<pair<vector<int>::const_iterator,vector<int>::const_iterator>> ps(nums.size());
        transform(nums.begin(), nums.end(), ps.begin(), [](auto const &num) { 
            return make_pair(begin(num), end(num)); });

        auto less_val = [](auto i, auto j) { return *(i.first) < *(j.first); };
        auto max_i = max_element(ps.begin(), ps.end(), less_val);
        auto best_max = max_i->first;
        auto best_min = min_element(ps.begin(), ps.end(), less_val)->first;
        while (max_i->first != max_i->second) {
            for (auto &[begin, end] : ps) begin = upper_bound(begin, end, *(max_i->first)) - 1;
            auto min_i = min_element(ps.begin(), ps.end(), less_val);
            if (*max_i->first - *min_i->first < *best_max - *best_min)
             best_max = max_i->first, best_min = min_i->first;
            min_i->first++, max_i = min_i;
        }
        return {*best_min, *best_max};
    }
};
