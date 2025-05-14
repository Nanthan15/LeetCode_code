class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int n = s.length();
        unordered_map<char,int> freq;
        for(int i=0;i<n;i++) freq[s[i]]++;
        for(int i=1;i<=t;i++){
            int zf = freq['z'];
            freq['z'] = 0;
            for(char c ='y';c>='a';c--){
                freq[c+1]+=freq[c];
                freq[c]=0;
            }
            freq['a']+=zf;
            freq['b']+=zf;
        }
        int res =0;
        for(auto it:freq){
            res+=it.second;

        }
        return res;
        
    }
};