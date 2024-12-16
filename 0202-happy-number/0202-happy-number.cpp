#include <unordered_set>
#include <cmath>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> seen; // To keep track of numbers we've already seen
        while (n != 1) {
            if (seen.find(n) != seen.end()) {
                return false; // If we have seen the number before, it's a cycle
            }
            seen.insert(n);
            
            int sum = 0;
            while (n > 0) {
                int digit = n % 10; // Extract the last digit
                sum += digit * digit; // Add the square of the digit to the sum
                n /= 10; // Remove the last digit
            }
            n = sum; // Update n to the sum of squares
        }
        return true; // If n becomes 1, it's a happy number
    }
};
