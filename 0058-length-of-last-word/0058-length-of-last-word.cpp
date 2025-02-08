class Solution {
public:
    int lengthOfLastWord(string s) {
        int curr = s.size() - 1;
        int cnt = 0;

        // Skip any trailing spaces
        while (curr >= 0 && s[curr] == ' ') curr--;

        // Count the characters of the last word
        while (curr >= 0 && s[curr] != ' ') {
            cnt++;
            curr--;
        }

        return cnt;
    }
};
