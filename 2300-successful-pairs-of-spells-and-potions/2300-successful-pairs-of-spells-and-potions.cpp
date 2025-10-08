class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
       int n=spells.size();
       vector<int> ans(n);
       int m=potions.size();
       for(int i=0; i<n;i++){
          int low=0;
          int high=m-1;
          int index=-1;
          while(low<=high){
              int mid=(low+high)/2;
              long long prod=(long long)spells[i]* (long long)potions[mid];
              if(prod>=success)
              {
                  index=mid;
                  high=mid-1;
              }
              else
              {
                  low=mid+1;
              }
          }
          if(index!=-1){
              ans[i]=m-index;
          }

       }
       return ans;
        
    }
};