class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
       
        int n=arr.size(), i=0, j=n-1, ans=0;
        while (i<n-1 && arr[i]<=arr[i + 1]){ //O(n) | Prefix Array
            i++;
        }

        if (i==j) // If Already Sorted
            return 0;

        while (j>0 && arr[j-1]<=arr[j]){ // O(n) | Suffix Array
            j--;
        }

        ans = min(j, n-i-1);
        int left = 0, right = j;
        while (left <= i && right < n) // O(n) | Merging Step
        {
            if (arr[left] <= arr[right]) {
                ans = min(ans, right - left - 1); 
                left++; 
            } 
            else {
                right++; 
            }
        }

        return ans; 
    }
};