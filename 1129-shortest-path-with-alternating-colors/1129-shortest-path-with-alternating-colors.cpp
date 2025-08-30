class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<vector<int>>> graph(n,vector<vector<int>>(2));

        for(auto &e: redEdges){
            graph[e[0]][0].push_back(e[1]);
        }

        for(auto &e: blueEdges){
            graph[e[0]][1].push_back(e[1]);
        }

        vector<int> answer(n,-1);

        vector<vector<bool>> vis(n,vector<bool>(2,false));
        queue<array<int,3>> q;

        q.push({0,0,0});
        q.push({0,1,0});
        // inform of {u->v,0-> red && 1-> blue {node,colour,dist}};
        vis[0][0] = vis[0][1] = true; //both blue and red visted
        answer[0]=0;

        while(!q.empty()){
            auto [node,color,dist] = q.front();
            q.pop();


            if(answer[node]==-1) answer[node]=dist;
            else answer[node] = min(answer[node],dist);

            int nextcolour = 1-color;
            for(int nei: graph[node][nextcolour]){
                if(!vis[nei][nextcolour]){
                    vis[nei][nextcolour]= true;
                    q.push({nei,nextcolour,dist+1});
                }
            }
        }

        return answer;

        
    }
};