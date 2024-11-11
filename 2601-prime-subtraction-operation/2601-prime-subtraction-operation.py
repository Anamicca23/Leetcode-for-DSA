class Solution:
    def primeSubOperation(self, nums: list[int]) -> bool:
        def getMaxElement(nums):
            return max(nums)
        
        maxElement = getMaxElement(nums)
        
        # Create Sieve of Eratosthenes array to identify prime numbers
        sieve = [True] * (maxElement + 1)
        sieve[1] = False
        
        for i in range(2, int((maxElement + 1) ** 0.5) + 1):
            if sieve[i]:
                for j in range(i * i, maxElement + 1, i):
                    sieve[j] = False
        
        # Check if array can be made strictly increasing by subtracting prime numbers
        currValue = 1
        i = 0
        while i < len(nums):
            difference = nums[i] - currValue
            
            # Return false if current number is already smaller than required value
            if difference < 0:
                return False
            
            # Move to next number if difference is prime or zero
            if sieve[difference] == True or difference == 0:
                i += 1
                currValue += 1
            else:
                currValue += 1
                
        return True