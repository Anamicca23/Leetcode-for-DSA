class Solution {
public:
    string convert(string s, int numRows) {
        if(s.length()<3 || numRows==1)
        {
            return s;
        }
        vector<string>vec(numRows);
        int j=0, i=0;
        string res="";
        while(i<s.length())
        {
            while(j<numRows && i<s.length())
            {
                vec[j++] +=s[i++];
            }
            if(j==numRows)
            j=numRows-2;

            while(j>=0 && i<s.length())
            {
                vec[j--] += s[i++];
            }
            if(j==-1)
            j=1;
        }
        for(int i=0; i<vec.size(); i++)
        {
            res +=vec[i];
        }
        return res;
    }
};