class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
    int ans = 0;
    map<int, int> mp;
    for(auto m: meetings){ mp[m[0]] += 1; mp[m[1]+1] -= 1; }
    auto it = mp.begin(); 
    ans += it->first - 1;      // add to the answer, all the days those are available form day 1 to first meeting day
    it++;
    while(it != mp.end()){
        it->second += prev(it)->second;
        if(it->first <= days && it->second == 0) {
            int end = days+1;
            if(next(it) != mp.end()) end = next(it)->first;  // update the ending day 
            ans += end - it->first;                          // update ans as the diff of the current day no and end day 
        }
        it++;
    }
    return ans;
}
};