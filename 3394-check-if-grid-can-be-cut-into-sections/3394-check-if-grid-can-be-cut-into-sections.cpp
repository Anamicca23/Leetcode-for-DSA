const int N=200000;
unsigned X[N], Y[N];// pair (x, isStart)-> (x<<1)+isSart
class Solution {
public:
    bool cut3(unsigned* X, int M){
        sort(X, X+M);
        int sum=0, touch0=0;
        for(int i=0; i<M-1; i++){// last end not used
            sum+=(X[i]&1)*2-1;
            touch0+=sum==0;
            if (touch0>=2) return 1;
        }
        return 0;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        const int m=rectangles.size(), M=m*2;
        int i=0;
        for(auto& r: rectangles){
            unsigned xs=r[0], ys=r[1], xe=r[2], ye=r[3];
            X[i]=(xs<<1)+1; Y[i++]=(ys<<1)+1;
            X[i]=(xe<<1)  ; Y[i++]=(ye<<1); 
        }
        return cut3(X, M) || cut3(Y, M);
    }
};