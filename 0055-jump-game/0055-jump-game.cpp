class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        int final = nums[n-1];
        int maxi=0;
        for(int i=0;i<n;i++){
            //maxi = max(maxi,nums[i]);
            if(i+nums[i]>=n-1){
                return true;
            }
        }
        return false; 

        
    }
};