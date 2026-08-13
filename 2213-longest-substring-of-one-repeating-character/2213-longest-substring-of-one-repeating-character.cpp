class Solution {
public:
    void buildSegTree(int index , int l , int r , vector<pair<int,int>>& segTree , string& s , vector<int>& maxis){
        if(l == r){
            segTree[index].first = 1;
            segTree[index].second = 1;
            maxis[index] = 1;
            return ;
        }
        int mid = (l+r)/2;
        buildSegTree(index*2+1 , l , mid , segTree , s , maxis); 
        buildSegTree(index*2+2 , mid+1 , r , segTree , s , maxis);
        if(s[mid] == s[mid+1]){
            maxis[index] = max(segTree[index*2+1].second + segTree[index*2+2].first , max(maxis[index*2+1] ,maxis[index*2+2]));
            if((mid-l)+1 == segTree[index*2+1].second && (r-(mid+1))+1 == segTree[index*2+2].first){
                int x = segTree[index*2+1].second + segTree[index*2+2].first;
                segTree[index].first = x;
                segTree[index].second = x;   
            }else if((mid-l)+1 == segTree[index*2+1].second){
                segTree[index].first = ((mid-l)+1) + segTree[index*2+2].first;
                segTree[index].second = segTree[index*2+2].second;
            }else if((r-(mid+1))+1 == segTree[index*2+2].first){
                segTree[index].first = segTree[index*2+1].first;
                segTree[index].second = segTree[index*2+1].second + ((r-(mid+1))+1);
            }else {
                segTree[index].first = segTree[index*2+1].first;
                segTree[index].second = segTree[index*2+2].second;
            }
            return ;
        }
        segTree[index].first = segTree[index*2+1].first;
        segTree[index].second = segTree[index*2+2].second;
        maxis[index] = max(maxis[index*2+1] ,maxis[index*2+2]);    
    }
    void update(int changeIndex , char newChar , vector<pair<int,int>>& segTree , string& s , vector<int>& maxis , int index , int l , int r){
        if(l == r && l == changeIndex){
            s[l] = newChar;
            return ;
        }
        int mid = (l+r)/2;
        if(mid >= changeIndex){
            update(changeIndex , newChar , segTree , s , maxis , index*2+1 , l , mid);
        }else update(changeIndex , newChar , segTree , s , maxis , index*2+2 , mid+1 , r);
        if(s[mid] == s[mid+1]){
            maxis[index] = max(segTree[index*2+1].second + segTree[index*2+2].first,max(maxis[index*2+1] ,maxis[index*2+2]));
            if((mid-l)+1 == segTree[index*2+1].second && (r-(mid+1))+1 == segTree[index*2+2].first){
                int x = segTree[index*2+1].second + segTree[index*2+2].first;
                segTree[index].first = x;
                segTree[index].second = x;   
            }else if((mid-l)+1 == segTree[index*2+1].second){
                segTree[index].first = ((mid-l)+1) + segTree[index*2+2].first;
                segTree[index].second = segTree[index*2+2].second;
            }else if((r-(mid+1))+1 == segTree[index*2+2].first){
                segTree[index].first = segTree[index*2+1].first;
                segTree[index].second = segTree[index*2+1].second + ((r-(mid+1))+1);
            }else {
                segTree[index].first = segTree[index*2+1].first;
                segTree[index].second = segTree[index*2+2].second;
            }
            return ;
        }
        segTree[index].first = segTree[index*2+1].first;
        segTree[index].second = segTree[index*2+2].second;
        maxis[index] = max(maxis[index*2+1] ,maxis[index*2+2]); 
    }
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.size();
        vector<pair<int,int>> segTree(4*n);
        vector<int> maxis(4*n); 
        buildSegTree(0,0,n-1 , segTree , s , maxis); 
        int index = 0;   
        vector<int> res;
        for(int i = 0; i<queryCharacters.size() ;i++){
            update(queryIndices[i] , queryCharacters[i] , segTree , s , maxis , 0 , 0 , n-1); 
            res.push_back(maxis[0]);
        }
        return res;
    }
};