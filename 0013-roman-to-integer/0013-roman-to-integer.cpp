class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int result = 0;
        
        // Mapping of Roman numerals to integers
        unordered_map<char, int> romanMap = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        for (int i = 0; i < n; i++) {
            // Check if the next numeral is greater, indicating a subtractive combination
            if (romanMap[s[i]] < romanMap[s[i + 1]]) {
                result -= romanMap[s[i]];
            } else {
                result += romanMap[s[i]];
            }
        }
        
        return result;
    }
};
