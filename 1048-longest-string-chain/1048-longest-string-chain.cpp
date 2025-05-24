class Solution {
public:
    // Function to check if s2 is a predecessor of s1
    bool compare(string& s1, string& s2) {
        if (s1.size() != s2.size() + 1) return false;

        int i = 0, j = 0;
        while (i < s1.size()) {
            if (j < s2.size() && s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                i++; // skip one character in s1 (only once)
            }
        }
        return (i == s1.size() && j == s2.size());
    }

    // Sort by length of the strings
    static bool comp(string& s1, string& s2) {
        return s1.size() < s2.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // Sort words based on their lengths
        sort(words.begin(), words.end(), comp);

        vector<int> dp(n, 1);
        int maxLen = 1;

        // Classic DP on sequence
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (compare(words[i], words[prev]) && dp[prev] + 1 > dp[i]) {
                    dp[i] = dp[prev] + 1;
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
