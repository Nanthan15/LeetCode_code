class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int v = rooms.size();
        vector<int> vis(v, 0);
        queue<int> q;
        vis[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : rooms[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        for (auto i : vis) {
            if (!i) return false;
        }
        return true;
    }
};
