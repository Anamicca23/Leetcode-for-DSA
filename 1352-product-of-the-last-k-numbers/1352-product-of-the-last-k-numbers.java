class ProductOfNumbers {
    List<Integer> listProduct;

    public ProductOfNumbers() {
        listProduct=new ArrayList();
        listProduct.add(1);
    }
    
    public void add(int num) {
        if(num==0){
            listProduct=new ArrayList();
            listProduct.add(1);
        }else{
            listProduct.add(listProduct.get(listProduct.size()-1)*num);    
        }    
    }
    
    public int getProduct(int k) {
        if(k>listProduct.size()-1){
            return 0;
        }
        else{
            return listProduct.get(listProduct.size()-1)/listProduct.get(listProduct.size()-1-k);
        }
        
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */