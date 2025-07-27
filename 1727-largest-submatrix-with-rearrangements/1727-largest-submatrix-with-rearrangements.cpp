class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> height = matrix; // copy matrix for height calculation
        
        // Step 1: Calculate heights
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    height[i][j] += height[i-1][j];
                }
            }
        }

        int maxArea = 0;
        // Step 2 & 3: Sort each row and find max area
        for (int i = 0; i < m; i++) {
            sort(height[i].begin(), height[i].end(), greater<int>()); // sort descending
            for (int j = 0; j < n; j++) {
                maxArea = max(maxArea, height[i][j] * (j + 1));
            }
        }
        return maxArea;
    }
};
