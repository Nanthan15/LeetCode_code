class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();  // Correctly get the size of the vector
        //sort(citations.begin(), citations.end());  // Sort the array in ascending order

        int l = 0, r = n - 1;  // Set the binary search range correctly (0 to n-1)
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int val = n - mid;  

            if (citations[mid] == val) {
                return val;  
            } else if (citations[mid] < val) {
                l = mid + 1;  
            } else {
                r = mid - 1;  
            }
        }

        // If no exact match was found, the best possible h-index is 'n - l'
        return n - l;
        
    }
};