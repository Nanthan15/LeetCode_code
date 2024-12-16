class Solution {
public:
    bool isseq(string str1,string str2, int m,int n,int s,int t){
        if(m==s) return true;
        if(n==t) return false;

        if(str1[m]==str2[n])
            return isseq(str1,str2,m+1,n+1,s,t);
        return isseq(str1,str2,m,n+1,s,t);
    }
    bool isSubsequence(string s, string t) {
        int m=s.size();
        int n = t.size();
        return isseq(s,t,0,0,m,n);   
    }
};
