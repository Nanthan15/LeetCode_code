class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n =events.size();

        sort(events.begin(),events.end(),[](auto &a, auto &b){
            return a[1]<b[1];
        });

        vector<int> endtim;
        for(auto &e : events) endtim.push_back(e[1]);

        vector<vector<int>> dp(n+1,vector<int>(k+1,0));

        for(int i=1;i<=n;i++){
            int start = events[i-1][0], end = events[i-1][1], val = events[i-1][2];
            int prev = lower_bound(endtim.begin(),endtim.end(),start) - endtim.begin();

            for(int j=1;j<=k;j++){
                dp[i][j] = max(dp[i][j],dp[i-1][j]);
                dp[i][j] = max(dp[i][j],dp[prev][j-1]+val);
            }
        }

        return dp[n][k];
        
    }
};