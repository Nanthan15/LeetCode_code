class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    long long sum = 0;
    int i = 0; // pointer to iterate through nums
    long long curr = 1;

    while (k > 0) {
        // Skip if curr is present in nums
        if (i < nums.size() && nums[i] == curr) {
            i++;
        } else {
            sum += curr;
            k--;
        }
        curr++;
    }

    return sum;
        
        
    }
};