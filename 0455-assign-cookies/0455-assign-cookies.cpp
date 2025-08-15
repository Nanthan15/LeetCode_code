class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int l=0;
        int r =0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n = g.size();
        int m = s.size();
        int cnt =0;
        while(l<n && r<m){
            if(g[l]<=s[r]){
                l++;
                r++;
                cnt++;
            }
            else{
                r++;
            }
        }
        return cnt;

        
    }
};