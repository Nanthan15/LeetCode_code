class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxi = values[0], ans = 0;
        for(int i=1; i<values.size(); i++){
            maxi = max(maxi-1, values[i-1]-1);
            ans = max(ans, values[i] + maxi);
        }
        return ans;
    }
};

auto speedup = []()
{ios::sync_with_stdio(0);
 cin.tie(0);
 cout.tie(0);
 return 0;}();