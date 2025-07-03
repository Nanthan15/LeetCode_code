class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> flat;
        
        // Step 1: Flatten the matrix
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                flat.push_back(matrix[i][j]);
            }
        }

        
        sort(flat.begin(), flat.end());

        
        int low = 0, high = flat.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (mid == k - 1) {
                ans = flat[mid];
                break;
            }
            else if (mid > k - 1) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
