class Solution {
public:
    bool dfs(const vector<vector<int>>& graph, int src, int color,
             map<int, int>& group) {
        if (group.count(src))
            return group[src] == color;
        group[src] = color; // assign group/color (0 or 1)

        for (const auto& next : graph[src])
            if (!dfs(graph, next, 1 - color, group))
                return false;

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n);
        map<int, int> group{};
        for (const auto& dis : dislikes) {
            graph[dis[0] - 1].push_back(dis[1] - 1);
            graph[dis[1] - 1].push_back(dis[0] - 1);
        }
        for (int i = 0; i < n; ++i)
            if (!group.count(i) && !dfs(graph, i, 0, group))
                return false;

        return true;
    }
};