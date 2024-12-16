class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int count = 0;
        int i = 0;  // Index for string s
        int j = 0;  // Index for string t
        
        // Loop through string t
        while (i < n && j < m) {
            if (s[i] == t[j]) {
                count++;
                i++;  // Move to the next character in s
            }
            j++;  // Always move to the next character in t
        }

        // If count equals the size of s, then all characters were matched
        return count == n;
    }
};
