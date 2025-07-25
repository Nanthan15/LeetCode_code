class Solution {
public:
    int largestInteger(int num) {
        vector<int> digits;
        vector<int> evenDigits;
        vector<int> oddDigits;

        
        int temp = num;
        while (temp > 0) {
            int d = temp % 10;
            digits.push_back(d);
            if (d % 2 == 0)
                evenDigits.push_back(d);
            else
                oddDigits.push_back(d);
            temp /= 10;
        }

        
        reverse(digits.begin(), digits.end());

        
        sort(evenDigits.begin(), evenDigits.end(), greater<int>());
        sort(oddDigits.begin(), oddDigits.end(), greater<int>());

        
        int evenIndex = 0, oddIndex = 0;
        for (int i = 0; i < digits.size(); ++i) {
            if (digits[i] % 2 == 0) {
                digits[i] = evenDigits[evenIndex++];
            } else {
                digits[i] = oddDigits[oddIndex++];
            }
        }

        
        int result = 0;
        for (int d : digits) {
            result = result * 10 + d;
        }

        return result;
    }
};