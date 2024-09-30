class CustomStack {
  vector<int> incremental;
  vector<int> container;
  int cap;
public:
  CustomStack(int maxSize): cap(maxSize) {}
  
  void push(int x) {
    if(container.size() == cap) return;
    container.push_back(x);
    incremental.push_back(0);
  }
  
  int pop() {
    if(container.empty()) return -1;
    int result = container.back() + incremental.back();
    container.pop_back();
    if(incremental.size() > 1) incremental[incremental.size() - 2] += incremental.back();
    incremental.pop_back();
    return result;
  }
  
  void increment(int k, int val) {
    if(container.empty()) return;
    k = min<int>(k - 1, container.size() - 1);
    incremental[k] += val;
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */