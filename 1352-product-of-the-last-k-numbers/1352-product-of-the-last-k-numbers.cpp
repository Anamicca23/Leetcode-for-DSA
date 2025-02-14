int product[40000];
class ProductOfNumbers {
public:
    int n=1;
    ProductOfNumbers(){
        product[0]=1;
    }
    
    void add(int num) {
        if (num==0) {
            n=1;
        }
        else{
            product[n]=product[n-1]*num;
            n++;
        }
    }
    
    int getProduct(int k) {
        if (n<=k) return 0;
        return product[n-1]/product[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */