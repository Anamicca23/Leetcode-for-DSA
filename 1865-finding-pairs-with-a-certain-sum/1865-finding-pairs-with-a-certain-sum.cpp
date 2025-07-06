class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int, int> freq;
    int n, xMax=0;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2): nums1(nums1),nums2(nums2), n(nums1.size()) {
        sort(this->nums1.begin(), this->nums1.end());
        freq.reserve(100000);
        for(int x: nums2){
            freq[x]++;
            xMax=max(xMax, x);
        }
    }
    
    void add(int index, int val) {
        int x=nums2[index];
        if (--freq[x]==0) freq.erase(x);
        nums2[index]+=val;
        freq[x+val]++;
        if (x+val>xMax) xMax=x+val;
    }
    
    int count(int tot) {
        int cnt=0;
        int i0=lower_bound(nums1.begin(), nums1.end(), max(1, tot-xMax))-nums1.begin();
        for(int i=i0; i<n; i++){
            const int y=nums1[i];
            if (y>=tot) break;
            cnt+=freq[tot-y];
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */