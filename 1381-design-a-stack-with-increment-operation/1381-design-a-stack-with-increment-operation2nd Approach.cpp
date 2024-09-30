static const int speedup = []{ios::sync_with_stdio(0); cin.tie(0); return 0;}();
int stk[2000];

class CustomStack {
    int sz, smax, d;
public:
    CustomStack(int maxSize) : sz{0}, smax{2*maxSize}, d{0} {}
    void push(int x) {
        if (sz != smax) stk[sz++] = x-d, stk[sz++] = 0;
    }
    
    int pop() {
        if (!sz) return -1;
        d += stk[--sz];
        return d + stk[--sz];
    }
    
    void increment(int k, int val) {
        if (sz) stk[min(sz, 2*k) - 1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */