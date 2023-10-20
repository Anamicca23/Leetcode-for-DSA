class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(), arr.end()); //sorting the array
        int i=0, j=0, n=arr.size();
        while (i<n && j<n) {
            //two pointer
            while (j<n && arr[j] < 2*arr[i]) j++;  ///if given both condition exists it return true
            if (! (j<n)) break;    //i!=j
            if (arr[j] == 2*arr[i] && i!=j) return true; //arr[i]=2*arr[j] 
            i++;
        }
        return false;   //else false
    }
};