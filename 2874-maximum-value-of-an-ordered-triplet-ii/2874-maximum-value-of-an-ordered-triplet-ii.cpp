class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0;

        vector<int> suffixMax(n, 0);
        suffixMax[n - 1] = nums[n - 1];

        // Compute suffix max values
        for (int i = n - 2; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], nums[i]);
        }

        int maxI = nums[0];
        long long maxValue = 0;

        for (int j = 1; j < n - 1; ++j) {
            if (maxI > nums[j]) {
                maxValue = max(maxValue,
                               (long long)(maxI - nums[j]) * suffixMax[j + 1]);
            }
            maxI = max(maxI, nums[j]);
        }

        return maxValue;
    }
};