class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;  // Track the farthest index we can reach

        // Loop through the array
        for (int i = 0; i < n; i++) {
            // If we cannot reach index i, return false
            if (i > maxi) {
                return false;
            }
            
            // Update the farthest index we can reach
            maxi = max(maxi, i + nums[i]);

            // If we can reach or surpass the last index, return true
            if (maxi >= n - 1) {
                return true;
            }
        }

        return false;  // If we finish the loop and can't reach the last index
    }
};
