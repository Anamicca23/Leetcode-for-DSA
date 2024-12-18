class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> result(prices.begin(),prices.end());
        stack<int>st;
        for(int i=0; i<prices.size();i++){
            while(!st.empty() and prices[i]<=prices[st.top()]){
              result[st.top()]-=prices[i];
              st.pop();
            }
            st.push(i);
        }
        return result;
    }
};