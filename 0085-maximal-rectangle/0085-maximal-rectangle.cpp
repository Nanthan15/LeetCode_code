class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> height(m, 0);     // DP: Heights of histograms
        vector<int> left(m, 0);       // DP: Left boundary
        vector<int> right(m, m);      // DP: Right boundary (exclusive)
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int curLeft = 0, curRight = m;

            // 1. Update height
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1')
                    height[j]++;
                else
                    height[j] = 0;
            }

            // 2. Update left
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == '1')
                    left[j] = max(left[j], curLeft);
                else {
                    left[j] = 0;
                    curLeft = j + 1;
                }
            }

            // 3. Update right
            for(int j = m - 1; j >= 0; j--) {
                if(matrix[i][j] == '1')
                    right[j] = min(right[j], curRight);
                else {
                    right[j] = m;
                    curRight = j;
                }
            }

            // 4. Update maxArea
            for(int j = 0; j < m; j++) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxArea;
    }
};
