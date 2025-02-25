class Solution {
public:
 int numOfSubarrays(vector<int>& arr) {
    int odd = 0, even = 0, sum = 0;
    for (int n : arr) {
        if (n % 2) {
            swap(odd, even);
            ++odd;
        }
        else
            ++even;
        sum = (sum + odd) % 1000000007;
    }
    return sum;
}
};