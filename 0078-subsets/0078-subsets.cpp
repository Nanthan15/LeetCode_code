class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = s.size();
        vector<int> ans;
        for (int num = 0; num < (1 << n); num++) {
            int sub = "";
            for (int i = 0; i < n; i++) {
                // check if the ith bit is set or not
                if (num & (1 << i)) {
                    sub += s[i];
                }
            }
            if (sub.size() > 0) {
                ans.push_back(sub);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};