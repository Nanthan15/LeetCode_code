class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int currzero = 0, prevzero =0,one =0,zeroseg=0,maxonces=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0') currzero++;
            else{
                one++;
                maxonces = max(maxonces,currzero+prevzero);
                if(currzero!=0){
                    prevzero = currzero;
                    zeroseg++;
                }
                currzero=0;

            }
        }

        if(currzero!=0) zeroseg++;
        maxonces = max(maxonces,currzero+prevzero);
        return one + ((zeroseg>1)?maxonces:0);
    }
};