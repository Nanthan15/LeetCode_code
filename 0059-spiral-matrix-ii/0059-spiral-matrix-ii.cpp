class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n,vector<int>(n));
        int left =0,right = n-1 , top =0,bottom = n-1,nums=1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++) res[top][i] = nums++;
            top++;
            for(int i=top;i<=bottom;i++) res[i][right] = nums++;
            right--;
            for(int i=right;i>=left;i--) res[bottom][i] = nums++;
            bottom--;
            for(int i=bottom;i>=top;i--) res[i][left] = nums++;
            ++left;
        }
        return res;
    }
};