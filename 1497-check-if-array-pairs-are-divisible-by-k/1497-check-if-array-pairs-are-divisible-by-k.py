class Solution:
    def canArrange(self, arr, k):
        remainder_count = [0] * k
        for num in arr:
            rem = (num % k + k) % k  
            remainder_count[rem] += 1
        if remainder_count[0] % 2 != 0:
            return False  
        
        for i in range(1, k // 2 + 1):
            if remainder_count[i] != remainder_count[k - i]:
                return False 
        
        return True