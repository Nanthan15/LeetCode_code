class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        // sliding window approach
        int max_count = 0;
        int win_count = 0;
        int left = 0, right = 0;
        int n = nums.size();
        while (right < n) {
            while (right < n && (nums[right] - nums[left]) <= 2 * k) {
                win_count++;
                right++;
            }

            max_count = max(max_count,win_count);
            if(right==n) break;

            while(left<=right && (nums[right] - nums[left]) > 2 * k ){
                win_count--;
                left++;

            }
        }

        return max_count;
    }
};