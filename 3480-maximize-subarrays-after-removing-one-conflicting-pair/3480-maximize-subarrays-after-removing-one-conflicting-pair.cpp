class Solution {
public:
    long long countValid(int n, vector<vector<int>>& con) {
        vector<int> lastseen(n + 1, -1);
        long long total = 0;
        int left = 1;

        for (int right = 1; right <= n; right++) {
            for (int other : con[right]) {
                if (lastseen[other] >= left) {
                    left = lastseen[other] + 1;
                }
            }
            lastseen[right] = right;
            total += (right - left + 1);
        }
        return total;
    }

    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        int m = conflictingPairs.size();
        long long best = 0;

        for (int skip = 0; skip < m; skip++) {
            vector<vector<int>> con(n + 1);
            for (int i = 0; i < m; i++) {
                if (i == skip) continue;
                int a = conflictingPairs[i][0];
                int b = conflictingPairs[i][1];
                con[a].push_back(b);
                con[b].push_back(a);
            }
            best = max(best, countValid(n, con));
        }
        return best;
    }
};
