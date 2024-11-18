class Solution {
public:
    unordered_map<int, int> mem;
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        if (mem.find(n) != mem.end()) return mem[n];
        mem[n] = fib(n-1) + fib(n-2);
        return mem[n];
    }
};