class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxLength = 0;
        int currentAND = 0;
        int left = 0;
        
        for (int right = 0; right < n; ++right) {
            // If the bitwise AND is non-zero between current subarray, shrink the window from the left
            while ((currentAND & nums[right]) != 0) {
                currentAND ^= nums[left];  // Remove the effect of nums[left]
                left++;  // Move the left pointer to the right
            }
            
            currentAND |= nums[right];  // Include nums[right] in the current AND calculation
            maxLength = max(maxLength, right - left + 1);  // Update the maximum length
        }
        
        return maxLength;
    }
};
