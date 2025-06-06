class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;
        for(int num: nums){
            arr.push_back(to_string(num));
        }
        
        sort(arr.begin(),arr.end(),[](const string&a,const string &b){
            return(b+a)<(a+b);
            
        });
        
        if(arr[0]=="0") return "0";
        string lar;
        for(const string &num : arr){
            lar+=num;
        }
        return lar;
        
        
        
    }
};