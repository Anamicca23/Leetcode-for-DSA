class Solution {
public:
    static inline bool partition(int x, int target) {
        if (x==target) return 1;
        if (x==0) return target==0; 
        const int m0=min(x, 1000); 
        [[unroll]] 
        for (int m=10; m<=m0; m*=10) {
            if (partition(x/m, target-x%m)) return 1;
        }
        return 0;
    }

    static int punishmentNumber(int n) {
        int sum=0;
        for (int i=1; i<=n; i++) {
            const int x=i*i;
            sum+=(partition(x, i))?x:0;
        }
        return sum;
    }
};