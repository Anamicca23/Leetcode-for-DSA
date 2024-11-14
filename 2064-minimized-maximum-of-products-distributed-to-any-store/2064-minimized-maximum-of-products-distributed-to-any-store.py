class Solution:
    def minimizedMaximum(self, storeCount: int, productQuantities: List[int]) -> int:
        maxQuantity = max(productQuantities)
        left = 1
        right = maxQuantity
        result = 0
        
        while left <= right:
            mid = left + (right - left) // 2
            if self.canDistributeProducts(mid, storeCount, productQuantities):
                result = mid
                right = mid - 1
            else:
                left = mid + 1
        
        return result
    
    def canDistributeProducts(self, maxProductsPerStore: int, storeCount: int, quantities: List[int]) -> bool:
        requiredStores = 0
        
        for quantity in quantities:
            # Calculate stores needed for current product type
            requiredStores += (quantity + maxProductsPerStore - 1) // maxProductsPerStore
        
        return requiredStores <= storeCount