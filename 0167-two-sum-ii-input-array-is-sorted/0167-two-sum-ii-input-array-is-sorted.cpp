class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n= numbers.size();
        int l=0,r=n-1;
        while(l<r){
            int val = numbers[l]+numbers[r];
            if(val==target){

                //l+1 and r+1 boz it is 1 based not 0 based
                return{l+1,r+1};
            }
            else if(target>val){
                l++;
            }
            else{
                r--;
            }
        }
        return {};
        
    }
};