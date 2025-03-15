class Solution {
    bool isPossible(vector<int> &arr, int k, int maxi) {
        int n = arr.size();
        int i = 0;
        while(i < n) {
            if(arr[i] <= maxi) {
                i += 2;
                k--;
            } else {
                i++;
            }

            if(k == 0) {
                return true;
            }
        }
        return false;
    }
public:
    int minCapability(vector<int>& arr, int k) {
        int n = arr.size();
        int low = *min_element(arr.begin(), arr.end());
        int high = *max_element(arr.begin(), arr.end());

        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isPossible(arr, k, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};