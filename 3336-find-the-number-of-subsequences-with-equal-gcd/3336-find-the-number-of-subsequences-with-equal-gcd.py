class Solution:
    def subsequencePairCount(self, nums: List[int]) -> int:
        MOD = 10 ** 9 + 7
        n = len(nums)
        @lru_cache(None)
        def solve(idx, g1, g2):
            if idx == n:
                return 1 if g1 != 0 and g1 == g2 else 0
            ans = solve(idx + 1, g1, g2)
            ng1 = nums[idx] if g1 == 0 else gcd(g1, nums[idx])
            ans = (ans + solve(idx + 1, ng1, g2)) % MOD
            ng2 = nums[idx] if g2 == 0 else gcd(g2, nums[idx])
            ans = (ans + solve(idx + 1, g1, ng2)) % MOD
            return ans
        return solve(0, 0, 0)