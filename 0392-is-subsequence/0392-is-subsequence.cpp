class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        int count = 0;
        // Index for string t
        unordered_map<int,int> mpp;
        
        for(int i=0;i<n;i++){
            mpp[s[i]]++;
        }

        for(int j=0;j<m;j++){
            if(mpp.find(t[j])!=mpp.end(t[j])){
                count++;
            }

        }

        return count==n;



        
    }
};
