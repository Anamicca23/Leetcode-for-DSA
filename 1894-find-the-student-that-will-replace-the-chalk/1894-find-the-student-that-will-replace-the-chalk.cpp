class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long total=0;
        for(auto i:chalk){
            total+=i;
            if(total>INT_MAX){
                total=INT_MAX;
                break;
            }
        }
        k=k%total;
        int ans=0;
        while(true){
          if(k>=chalk[ans]){
            k-=chalk[ans];
            ans++;
          }
          else{
            break;
          }
        }
        return ans;
    }
};