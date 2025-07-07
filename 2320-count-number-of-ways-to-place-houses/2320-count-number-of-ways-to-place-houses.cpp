class Solution {
    long long MOD = 1000000007;
public:
    int countHousePlacements(int n) {
        vector<long long> dp(n + 2); // to avoid index issues
    dp[0] = 1; // no plots
    dp[1] = 2; // one plot: [E], [H]

    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }

    // total = ways for side A * ways for side B
    return (dp[n] * dp[n]) % MOD;
        
    }
};