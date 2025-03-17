class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int n= nums.size();


        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }

        for (auto it : mpp) {
            if (it.second % 2 != 0) { // Check if the count is odd
                return false;  // Corrected `False` to `false`
            }
        }
        return true;
        
    }
};