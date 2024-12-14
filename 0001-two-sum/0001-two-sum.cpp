class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Create a vector of pairs, where each pair consists of the number and its original index
        vector<pair<int, int>> indexed_nums;
        for (int i = 0; i < nums.size(); i++) {
            indexed_nums.push_back({nums[i], i});
        }
        
        // Sort the vector by the value (nums[i])
        sort(indexed_nums.begin(), indexed_nums.end());

        int l = 0, r = indexed_nums.size() - 1;

        while (l < r) {
            int sum = indexed_nums[l].first + indexed_nums[r].first;
            if (sum == target) {
                return {indexed_nums[l].second, indexed_nums[r].second};
            } else if (sum < target) {
                l++;
            } else {
                r--;
            }
        }
        
        return {}; // In case no solution is found
    }
};
