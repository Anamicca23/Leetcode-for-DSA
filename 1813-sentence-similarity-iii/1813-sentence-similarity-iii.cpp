class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> v1, v2;
        stringstream ss(sentence1);
        string s;
        while(getline(ss,s,' ')){
            v1.push_back(s);
        }
        stringstream ss2(sentence2);
        while(getline(ss2,s,' ')){
            v2.push_back(s);
        }
        if(v1.size() > v2.size()) swap(v1,v2);
        while(v1.size()){
            if(v1.front() == v2.front()){
                v1.pop_front();
                v2.pop_front();
            } else if(v1.back() == v2.back()){
                v1.pop_back();
                v2.pop_back();
            } else {
                break;
            }
        }
        return v1.empty();
    }
};