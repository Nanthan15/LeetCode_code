class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;  
        int maxi = 0, l = 0, r = 0, currSum = 0;

        while (r < n) {
            if (mpp.find(nums[r]) != mpp.end() && mpp[nums[r]] >= l) {
                l = mpp[nums[r]] + 1;
            }            
            mpp[nums[r]] = r;
            currSum = 0;
            for (int i = l; i <= r; i++) {
                currSum += nums[i];
            }
            maxi = max(maxi, currSum);
            r++;
        }
        return maxi;
    }
};
