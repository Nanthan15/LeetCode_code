#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();

       
        int left = 0, right = n - 1, neg = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < 0) { 
                neg = mid + 1; 
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

       
        left = 0, right = n - 1;
        int pos = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > 0) {
                pos = n - mid; 
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return max(pos, neg);
    }
};
