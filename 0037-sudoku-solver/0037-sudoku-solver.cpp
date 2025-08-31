class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int res=0;
        int n=arr.size();
        int i=0,j=n-1;
        while(i<j){
            res=max(res, (j-i)*(min(arr[i],arr[j])));
            (arr[i]<=arr[j])?
                i++:j--;
        }
        return res;
    }
};