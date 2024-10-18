class Solution:
    def subset_count(self, idx, curr_or, nums, max_or, dp):
        # Base case: if we've processed all elements
        if idx == len(nums):
            return 1 if curr_or == max_or else 0
        
        # If the value is already computed, return it
        if dp[idx][curr_or] != -1:
            return dp[idx][curr_or]
        
        # Including the current element in the subset
        included = self.subset_count(idx + 1, curr_or | nums[idx], nums, max_or, dp)
        
        # Not including the current element in the subset
        not_included = self.subset_count(idx + 1, curr_or, nums, max_or, dp)
        
        # Storing the result in dp array and returning the sum of both choices
        dp[idx][curr_or] = included + not_included
        return dp[idx][curr_or]

    def countMaxOrSubsets(self, nums):
        max_or = 0
        for num in nums:
            max_or |= num
        
        # dp[idx][curr_or]: count of subsets using first 'idx' elements with current OR 'curr_or'
        dp = [[-1 for _ in range(max_or + 1)] for _ in range(len(nums))]
        
        # Start the recursive function
        return self.subset_count(0, 0, nums, max_or, dp)