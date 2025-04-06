class Solution {
public:
    void out(vector <int> v){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector <int> ret;
        int endPoint = 0;
        int retLen = 1;
        int n = nums.size();
        if(!n) return {};
        sort(nums.begin(), nums.end());
        vector <int> len(n, 1);
        vector <int> par(n, 0);
        for(int i = 1; i < n; i++){
            par[i] = i;
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0 && len[j] + 1 > len[i]){
                    len[i]  = len[j] + 1;
                    par[i] = j;
                }
            }
            if(len[i] > retLen){
                retLen = len[i];
                endPoint = i;
            }
        }
        //cout << endPoint << endl;
        ret.push_back(nums[endPoint]);
        //out(par);
        while(endPoint != par[endPoint]){
            endPoint = par[endPoint];
            ret.push_back(nums[endPoint]);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};