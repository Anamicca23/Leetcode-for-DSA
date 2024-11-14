class Solution {
    public int minimizedMaximum(int storeCount, int[] productQuantities) {
        int maxQuantity = 0;
        for (int quantity : productQuantities) {
            maxQuantity = Math.max(maxQuantity, quantity);
        }
        
        int left = 1;
        int right = maxQuantity;
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDistributeProducts(mid, storeCount, productQuantities)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return result;
    }
    
    private boolean canDistributeProducts(int maxProductsPerStore, int storeCount, int[] quantities) {
        int requiredStores = 0;
        
        for (int quantity : quantities) {
            // Calculate stores needed for current product type
            requiredStores += (quantity + maxProductsPerStore - 1) / maxProductsPerStore;
        }
        
        return requiredStores <= storeCount;
    }
}