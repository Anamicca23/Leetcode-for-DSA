class Solution {
public:
    int maxArea(vector<int>& height) {
        //we will see all possibility to store maximum amount of water
        //Time complexity:- O(n) by using two pointer
        //we are fixing left pointer at 0 and right pointer at last index
        int l=0;
        int r=height.size()-1;
        //assuming max capacity will be 0 inititally
        int maxi=0;
        //untill left pointer is less than right pointer
        while(l<r)
        {
            //first we take left pointer height and right pointer height
            int lh=height[l];
            int rh= height[r];
            //then we are calculating minimum height 
            int min_height=min(lh,rh);
            //here, max capacity will be min_height*(r-l)
            //if we are getting maximum capacity we will store in max
            int capacity=min_height*(r-l);
            maxi= max(maxi,capacity);
            //if height of left is less then will increase left ortherwise decrease right
            if(lh<rh)l++;
            else r--;
            //if we are getting maximum height we will return max in answer
        }
        return maxi;

    }
};