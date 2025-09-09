class Solution {
public:
    int mod = (long)(1000000007);
    int peopleAwareOfSecret(int n, int delay, int forget) {
        // This variable tracks the running count of people who are able to share the secret.
        long noOfPeopleWithSecret = 0;
        
        // dp[i] stores the number of people who learn the secret on day i.
        vector<long> dp(n+1, 0);
        dp[1] = 1;
        
        for(int i=2; i<=n; i++){
            // People who learned 'delay' days ago start sharing today.
            long noOfNewPeopleWithSecret = 0;
            if((i-delay)>=1)
                noOfNewPeopleWithSecret = dp[i-delay];
            
            // People who learned 'forget' days ago forget today and stop sharing.
            long noOfPeopleForgetSecret = 0;
            if((i-forget)>=1)
                noOfPeopleForgetSecret = dp[i-forget];
            
            // Update the count of active sharers.
            noOfPeopleWithSecret = (noOfPeopleWithSecret + noOfNewPeopleWithSecret - noOfPeopleForgetSecret + mod) % mod;
            
            // The number of new people learning today equals the number of people sharing.
            dp[i] = noOfPeopleWithSecret;
        }
        
        // The total number of people aware on day 'n' are those who learned
        // in the window [n - forget + 1, n], as they haven't forgotten yet.
        long ans=0;
        for(int i=n-forget+1; i<=n; i++){
            ans = (ans+dp[i])%mod;
        }
        return ((int)ans);
    }
};