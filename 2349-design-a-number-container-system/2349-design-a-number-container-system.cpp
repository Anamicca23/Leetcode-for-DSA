class NumberContainers {
public:
    map<int, int> mp;
    map<int, set<int>> mpp;
    
    NumberContainers() {}

    void change(int index, int number) {
        if(mp.find(index) != mp.end() && mp[index] != number) {
            mpp[mp[index]].erase(index);  
            if(mpp[mp[index]].empty()) {
                mpp.erase(mp[index]);
            }
        }
        mp[index] = number;
        mpp[number].insert(index);
    }

    int find(int number) {
        return mpp[number].empty() ? -1 : *mpp[number].begin();
    }
};