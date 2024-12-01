class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        const int n=arr.size();
        for(int i=0; i<n-1; i++){
            int x=arr[i];
            if (x>=0 && binary_search(arr.begin()+i+1, arr.end(), 2*x))
                return 1;
            else{
                if (x%2==0 && binary_search(arr.begin()+i+1, arr.end(), x/2))
                    return 1;
            }
        }
        return 0;
        
    }
};