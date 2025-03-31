class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0; 
        unordered_map<char, int> a;         
        int maxlen = 0;         
        while (r < n) {    
                

            if (a.find(s[r]) != a.end() && a[s[r]] >= l) {                
                l = a[s[r]] + 1;
            }
            a[s[r]] = r;           
            int len = r - l + 1;
            maxlen = max(maxlen, len);
            r++;
        }
        
        return maxlen; 
        
    }
};