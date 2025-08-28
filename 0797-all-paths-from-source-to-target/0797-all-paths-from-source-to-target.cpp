class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    void dfs(vector<vector<int>>& graph,int node,int target){
        path.push_back(node);
        if(node==target) res.push_back(path);
        else{
            for(int next:graph[node]){
                dfs(graph,next,target);
            }
        }
        path.pop_back();
        
           }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        dfs(graph,0,n-1);
        return res;
        
    }
};