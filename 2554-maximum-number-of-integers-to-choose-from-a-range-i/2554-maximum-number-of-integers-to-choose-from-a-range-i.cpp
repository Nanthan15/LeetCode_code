class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> mpp;
        for (auto num : banned) {
            mpp[num]++;
        }
        
        int cnt = 0, sum = 0;

        for (int i = 1; i <= n; i++) {
            if (mpp.find(i) == mpp.end() && sum + i <= maxSum) {
                cnt++;
                sum += i;
            }
        }

        return cnt;
    }
};
