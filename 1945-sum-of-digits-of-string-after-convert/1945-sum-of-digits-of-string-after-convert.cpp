class Solution {
public:
    int getLucky(string s, int k) {
        string currString;
        for (auto chr : s) {
            int numVal = static_cast<int>(chr - 'a' + 1);
            string currNum = to_string(numVal);
            currString.append(currNum);
        }
        while (k-- > 0) {
            currString = process(currString);
        }
        return stoi(currString);
    }

private:
    string process(const string& currString) {
        int digSum = 0;
        for (int indx = 0; indx < currString.length(); indx++) {
            char chr = currString[indx];
            int dig = chr - '0';
            digSum += dig;
        }
        return to_string(digSum);
    }
};