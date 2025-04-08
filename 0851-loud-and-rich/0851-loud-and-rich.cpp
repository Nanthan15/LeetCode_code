class Solution {
public:
    int dfs(unordered_map<int,vector<int>> &adj,vector<int>& quiet,vector<int> &ans,int node){
        int x = node;
        for(auto i: adj[node]){
            if(ans[i]!=-1){
                if(quiet[ans[i]]<quiet[x]){
                    x=ans[i];
                }
            }
            else{
                int y = dfs(adj,quiet,ans,i);
                if(quiet[x]>quiet[y]){
                    x=y;
                }

            }

            
        }
        return ans[node]=x;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        unordered_map<int,vector<int>> adj;
        vector<int> ans(n,-1);

        for(int i=0;i<richer.size();i++){
            adj[richer[i][1]].push_back(richer[i][0]);
    
        }

        for(int i=0;i<n;i++){
            if(ans[i]==-1){
                dfs(adj,quiet,ans,i);
            }
            
        }
        return ans;

        
    }
};