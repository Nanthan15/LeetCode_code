#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;   // Count the number of jumps
        int maxi = 0;  // To track the farthest we can reach in the current jump range
        int current_end = 0;  // To track the end of the current jump range

        if (n == 1) return 0;  // No jump needed if there's only one element

        for (int i = 0; i < n - 1; i++) {  // We don't need to consider the last element
            // Update the farthest point reachable from the current index
            maxi = max(maxi, i + nums[i]);

            // If we've reached the end of the current jump range
            if (i == current_end) {
                cnt++;  // We need to make a new jump
                current_end = maxi;  // Update the end of the new jump range

                // If we've already reached or surpassed the last index, break
                if (current_end >= n - 1) {
                    break;
                }
            }
        }
        
        return cnt;
    }
};
