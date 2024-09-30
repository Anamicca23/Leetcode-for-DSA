class CustomStack {
public:
    int *arr;
    int size,top;
    CustomStack(int maxSize) {
        size=maxSize;
        arr=new int[size];
        top=-1;
    }
    
    void push(int x) {
        if(size-top>1){
            top++;
            arr[top]=x;
        }
    }
    
    int pop() {
        if(top==-1)
            return -1;
        return arr[top--];
    }
    
    void increment(int k, int val) {
        int limit = min(k, top + 1);  
        for (int i = 0; i < limit; i++) {
            arr[i] += val;
        }
    }
    
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */