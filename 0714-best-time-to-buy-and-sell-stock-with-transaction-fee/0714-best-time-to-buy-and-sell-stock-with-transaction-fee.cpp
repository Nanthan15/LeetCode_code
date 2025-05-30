class Solution {
public:

    int f(int ind, int buy, vector<int>& val, int n, vector<vector<int>>& dp,int fee) {
        if (ind == n) return 0;  // Base case: no more days to process
        if (dp[ind][buy] != -1) return dp[ind][buy];  // If already computed

        long profit = 0;
        if (buy) {
            // Maximize profit by buying (i.e., -prices[ind]) or skipping this day
            profit = max(-val[ind]- fee + f(ind + 1, 0, val, n, dp,fee), 0 + f(ind + 1, 1, val, n, dp,fee));
        } else {
            // Maximize profit by selling (i.e., prices[ind]) or skipping this day
            profit = max(val[ind] + f(ind + 1, 1, val, n, dp,fee), 0 + f(ind + 1, 0, val, n, dp,fee));
        }
        return dp[ind][buy] = profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();  // Get the number of days
        vector<vector<int>> dp(n, vector<int>(2, -1));  // dp[ind][buy] initialized to -1
        return f(0, 1, prices, n, dp,fee);
        
    }
};