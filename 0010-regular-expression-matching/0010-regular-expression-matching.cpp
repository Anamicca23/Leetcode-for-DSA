int stringMatch(vector<vector<int>> & dp, string &s, string &p, int len_s, int len_p)
{
    //BASE CASE:-
    //initially, checking length of s and p is zero or not if it is we return true
    //that mean we had matched complete string
    if(len_s==0 && len_p==0)
       return 1;
    //if pattern had no value but string had then
    //we return false
    if(len_p==0)
      return 0;
    //we check wheather in the position of dp ,it contain -1 or not we will initiallize it with -1 otherwise  if it contain 1 or 0 we return that value by which we can less the camputation.
    if(dp[len_s][len_p] != -1)
      return dp[len_s][len_p];
    //now, we check p[len_p-1] is "*" or not we check how many character we had to repeat or also will check how much large is the range of repetation
    //initially,we call the fuction to match next to next character with all the character in the string i.e character containing before star is matching the string
    //we take length of reptation = 0 and in while loop we calculate length repeatation that char using * then we store that result .and will break loop at the point when repetation has to end.
    if(p[len_p-1]=='*')
    {
        int res=stringMatch(dp,s,p,len_s,len_p-2);
        int len_rep=0;
        while(1)
        {
         if(len_s-len_rep>0 && (s[len_s-1-len_rep]==p[len_p-2] || p[len_p -2] =='.'))
              len_rep++;
            else 
              break;
            res=res |(stringMatch(dp,s,p,len_s-len_rep,len_p-2));
        }
        return dp[len_s][len_p]=res;
    }
    //Now, we are checking  len_s=0 or not will update it  in dp then return
    if(len_s==0)
     return dp[len_s][len_p]=0;
    //if in pattern there is dot and position at which char present in string is matching with pattern then will call recursivly by decreasing length by 1...if this condition not hold we return 0.
    if(p[len_p-1]=='.' || s[len_s-1]==p[len_p-1])
      return dp[len_s][len_p]=stringMatch(dp,s,p,len_s-1,len_p-1);
    return dp[len_s][len_p]=0; 
}



class Solution {
public:
    bool isMatch(string s, string p) {
        //we will do by dynamic programming or recursion
        //initally, we define two variable which represent length of string s and of pattern p
        int len_s=s.length(), len_p=p.length();
        //we are defining vector of vecter dp which store the values which check wheather it matches pattern or not
        vector<vector<int>>dp(len_s+1,vector<int>(len_p + 1,-1));
        //we make a fuction here to check it is matching or not.
        //if match it will return true  if not match it will return false
        return stringMatch(dp , s , p, len_s, len_p);
    }
};