class Solution {
public:
    bool isSubsetSum(vector<int> arr, int sum) {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

        // Base cases
        for (int i = 0; i < n; i++)
            dp[i][0] = true; // Sum 0 is always possible

        // Check for the first element
        if (arr[0] <= sum)
            dp[0][arr[0]] = true;

        // Fill the DP table
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= sum; target++) {
                bool nottake =
                    dp[ind - 1][target]; // Exclude the current element
                bool take = false;

                if (arr[ind] <= target)
                    take = dp[ind - 1]
                             [target - arr[ind]]; // Include the current element

                dp[ind][target] = take || nottake; // Store the result
            }
        }

        return dp[n - 1][sum]; // Result for the full set and target sum
    }
    bool canPartition(vector<int>& nums) {

        int sum =0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+= nums[i];
        }


        if(sum%2) return false;
        int tar = sum/2;

        return isSubsetSum(nums,tar);


    }
};