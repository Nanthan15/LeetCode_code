class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int minlen = 0, sum = 0;
        int mini = INT_MAX; // Initialize mini to a large value

        int l = 0, r = 0;
        while (r < n) {
            // Add the current element to the sum
            sum += nums[r];
            r++; // Move the right pointer

            // Check if the current sum meets or exceeds the target
            while (sum >= target) {
                // Update the minimum length
                mini = min(mini, r - l); // r - l gives the length of the subarray
                sum -= nums[l]; // Subtract the leftmost element from the sum
                l++; // Move the left pointer to the right
            }
        }

        return (mini == INT_MAX) ? 0 : mini; // Return 0 if no valid subarray was found
    }
};