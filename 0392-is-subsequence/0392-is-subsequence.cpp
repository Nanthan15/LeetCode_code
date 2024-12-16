class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int count = 0;

        for (int i = 0; i < n; i++) {  // Loop through each character of s
            for (int j = 0; j < m; j++) {  // Loop through each character of t
                if (s[i] == t[j]) {
                    count++;
                    // Move to the next character in s
                    break;  // Exit the inner loop and continue to the next character in s
                }
            }
        }

        // If count is equal to the length of s, it means all characters were found
        return count == n;
    }
};
