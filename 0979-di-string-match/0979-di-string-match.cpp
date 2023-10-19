class Solution {
public:
    vector<int> diStringMatch(string s) {
         int i=0,j=s.length();
        vector <int> v;
        for(int it:s){
            if(it=='I'){ //if s is equal to I
                v.push_back(i++);  //and increment i,
            }
            else{
                 v.push_back(j--);  //if we found D than we push j and decrement it
            } 
        }             
        v.push_back(i);  
        return v;

    }
};