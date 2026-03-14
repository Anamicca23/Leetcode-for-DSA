class Solution {
public:
    string getHappyString(int n, int k) {
        int perCharCount=pow(2,n-1);
        if(3*perCharCount<k)return "";
        string ans="";
        if(k<=perCharCount){
            ans.push_back('a');
        }else if(k<=2*perCharCount){
            ans.push_back('b');
            k-=perCharCount;
        }else{
            ans.push_back('c');
            k-=2*perCharCount;
        }
        vector<string>options{"bc","ac","ab"};
        for(int i=1;i<n;i++){
            perCharCount/=2;
            string option=options[ans.back()-'a'];
            if(k<=perCharCount){
                ans.push_back(option[0]);
            }else{
                ans.push_back(option[1]);
                k-=perCharCount;
            }
        }
        return ans;
    }
};