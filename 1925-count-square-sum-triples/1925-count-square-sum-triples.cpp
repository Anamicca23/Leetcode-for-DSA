class Solution {
private:
    int gcd(int a, int b){
        while(b){
            a %= b;
            swap(a, b);
        }
        return a;
    }
public:
    int countTriples(int n) {
        int cnt = 0;
        for(int m = 2; m * m < n; m++){
            for(int k = 1; k < m; k++){
                if (gcd(m, k) == 1 && (m - k) % 2 == 1) {
                    int c_primitive = m * m + k * k;

                    if (c_primitive > n) {
                        break;
                    }
                    cnt += 2 * (n / c_primitive); 
                }
            }
        }
        return cnt;
    }
};