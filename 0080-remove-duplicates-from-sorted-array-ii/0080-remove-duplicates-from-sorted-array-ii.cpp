class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        if (n <= 2) return n;  // If there are 2 or fewer elements, return the length directly
        
        int k = 2;  // Since we can keep at most 2 duplicates of any number, start at index 2
        
        for (int i = 2; i < n; ++i) {
            if (nums[i] != nums[k - 2]) {  // Check if the current element is different from the element at position k-2
                nums[k] = nums[i];  // Move the element to the 'k' position
                k++;  // Increment k to write the next valid element
            }
        }
        
        return k;  // Return the length of the array with the allowed duplicates
    }
};
