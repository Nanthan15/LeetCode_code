class Solution {
public:
    vector<vector<int>> dp;

    int f(int i, int j, string &p, string &t) {
        if (i < 0 && j < 0) return true;
        if (i < 0 && j >= 0) return false;
        if (j < 0 && i >= 0) {
            for (int ii = 0; ii <= i; ii++) {
                if (p[ii] != '*') return false;
            }
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (p[i] == t[j] || p[i] == '?') {
            return dp[i][j] = f(i - 1, j - 1, p, t);
        }

        if (p[i] == '*') {
            return dp[i][j] = f(i - 1, j, p, t) | f(i, j - 1, p, t);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = p.size();
        int m = s.size();
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        return f(n - 1, m - 1, p, s);
    }
};
