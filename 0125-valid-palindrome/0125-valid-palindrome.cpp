class Solution {
public:
    bool isPalindrome(string s) {
        unordered_map<char, int> mpp;

        
        for(int i = 0; i < s.size(); i++) {
            if(isalnum(s[i])){
                mpp[tolower(s[i])]++;
            }
        }

        int oddcnt =0;
        for(auto it : mpp) {
            if(it.second % 2 != 0) {
                oddcnt++;
                if(oddcnt>1 ){
                    return false;
                }
                
            }
        }

        return true; 
    }
};
