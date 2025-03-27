class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(),nums.end());
        int minlen = 0, sum = 0;
        int mini = INT_MAX; 

        int l = 0, r = 0;
        while (r < n) {
            
            sum += nums[r];
            r++; 

           
            while (sum >= target) {
                
                mini = min(mini, r - l);
                sum -= nums[l]; 
                l++; 
            }
        }

        return (mini == INT_MAX) ? 0 : mini; // Return 0 if no valid subarray was found
    }
};