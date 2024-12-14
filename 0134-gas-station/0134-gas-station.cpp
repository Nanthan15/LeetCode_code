class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int m = cost.size();
        int gasrequired=0,costrequired=0;
        int start=0;
        for(int i=0;i<n;i++){
            gasrequired+=gas[i];
            costrequired+=cost[i];
            // if(gas[i]-cost[i]>=0 && start==-1){
            //     start=i;
            // }
        }
        if(gasrequired<costrequired) return -1;
        int remain=0;
        for(int i=0;i<n;i++){
            remain+=(gas[i]-cost[i]);
            if(remain<0){
                start=i+1;
                remain=0;
            }
        }
        return start;
        
    }
};