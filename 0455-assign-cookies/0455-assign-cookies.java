class Solution {
    public int findContentChildren(int[] g, int[] s) {

        //sort both the arrays, now both the greed and size array are arranged in increasing order,now start traversal from back 

//Our motive is to get top max size cookie which satisfies the greed traversing from largest to smallest..

//keep 1st pointer on greed array(say i) on the last index(ie. i=g.size-1) and 2nd on size array (say j) on the last index (j=s.size-1).


// Keep moving only 1st pointer on greed array and as we find suitable size(s[j]>=g[i]) increase the count and then move both the pointers on the respective arrays.

        Arrays.sort(g);
        Arrays.sort(s);
        int count=0;
        for(int i=g.length-1,j=s.length-1; j>=0 && i>=0 ;i--)
        {
            if(s[j]>=g[i]) 
            {
                count++;
                j--;
            }
        }
        return count;
   }
}

//time taken is nlog(n) for sorting and n for getting count,which makes it nlog(n)