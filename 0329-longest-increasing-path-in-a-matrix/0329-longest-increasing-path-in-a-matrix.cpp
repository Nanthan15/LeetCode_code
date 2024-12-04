class Solution {
public:
    vector<int> delrow = {-1, 0, 1, 0};  // Directions for moving up, right, down, left
    vector<int> delcol = {0, 1, 0, -1};

    int dfs(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& memo){
        if(memo[i][j]!=-1){
            return memo[i][j];
        }

        int n = matrix.size();
        int m = matrix[0].size();
        int max_len = 1;


        for(int k=0;k<4;k++){
            int new_i = i+delrow[k];
            int new_j = j+delcol[k];

            if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && matrix[new_i][new_j]>matrix[i][j]){
                max_len = max(max_len,1+dfs(new_i,new_j,matrix,memo));
            }
        }
        memo[i][j] = max_len;
        return max_len;

    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        vector<vector<int>> memo(n,vector<int>(m,-1));

        int long_path =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                long_path = max(long_path,dfs(i,j,matrix,memo));
            }
        }

        return long_path;         

    }
};