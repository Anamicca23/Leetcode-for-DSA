class Solution {
public:
    int numTeams(vector<int>& ratings) {

        int n = ratings.size();

        int teams = 0;

        for(int j = 1; j<n-1;j++){

            int smallerLeft = 0,smallerRight = 0;
            int largerRight = 0,largerLeft = 0;

            for(int i=0;i<j;i++){

                (ratings[i] > ratings[j])?largerLeft++:smallerLeft++;
                
            }

            for(int k =j+1;k<n;k++){

                (ratings[k] > ratings[j])?largerRight++:smallerRight++;
                
            }

            teams += (smallerLeft * largerRight) + (largerLeft * smallerRight);
            
        }

        return teams;
        
    }
};