class Solution {
    public String longestPalindrome(String s) {
        int start=0,end=0;
      for(int i=0; i<s.length();i++){
          int len1=expandingfrmcenter(s,i,i+1);
          int len2=expandingfrmcenter(s,i,i);
          int maxlen=Math.max(len1,len2);
          if(end-start<maxlen)
          {
              start=i-(maxlen-1)/2;
              end=i+maxlen/2;
          }
      }
      return s.substring(start,end+1);  
    }
    int expandingfrmcenter(String s, int i, int j)
    {
        while(i>=0 && j<s.length() && s.charAt(i)==s.charAt(j))
        {
            i--; j++;
        }
        return j-i-1;
    }
    
}