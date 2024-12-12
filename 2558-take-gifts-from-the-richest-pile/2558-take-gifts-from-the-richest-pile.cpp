#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    long long pickGifts(std::vector<int>& gifts, int k) {
        // Sort gifts in ascending order initially
        sort(gifts.begin(), gifts.end());

        long long sum = 0;
        int n = gifts.size();

        // Loop to apply k operations
        while(k > 0) {
            // Reduce the largest gift (last element) by taking its square root
            gifts[n - 1] = floor(sqrt(gifts[n - 1]));

            // Re-sort the vector after the modification
            sort(gifts.begin(), gifts.end());
            k--;  // Decrease the remaining operations
        }

        // Sum up the final values of the gifts
        for (auto it : gifts) {
            sum += it;
        }

        return sum;
    }
};
