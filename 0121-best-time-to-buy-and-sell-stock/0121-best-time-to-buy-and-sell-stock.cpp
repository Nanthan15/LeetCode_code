class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int mini=prices[0];
        int peo=0;

        for(int i=0;i<prices.size();i++){
            mini = min(prices[i],mini);
            peo = max(prices[i]-mini,peo);
        }
        return peo;
        
    }
};