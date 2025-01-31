class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> delrow = {1, 0, -1, 0};
        vector<int> delcol = {0, -1, 0, 1};

        unordered_map<int, int> islandSize;
        int islandId = 2;  // Start from 2 to differentiate from 0 & 1
        int maxIsland = 0;

        auto bfs = [&](int x, int y) -> int {
            queue<pair<int, int>> q;
            q.push({x, y});
            grid[x][y] = islandId;
            int size = 1;

            while (!q.empty()) {
                auto [cx, cy] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = cx + delrow[i], ny = cy + delcol[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1) {
                        grid[nx][ny] = islandId; // Mark with islandId
                        q.push({nx, ny});
                        size++;
                    }
                }
            }
            return size;
        };

        // Step 1: Find all islands and store their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int size = bfs(i, j);
                    islandSize[islandId++] = size;
                    maxIsland = max(maxIsland, size);
                }
            }
        }

        // Step 2: Check all 0s and see potential max island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIslands;
                    int potentialSize = 1;  // Flipping 0 to 1 adds 1

                    for (int k = 0; k < 4; k++) {
                        int ni = i + delrow[k], nj = j + delcol[k];
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] > 1) {
                            uniqueIslands.insert(grid[ni][nj]); // Unique island IDs
                        }
                    }

                    for (int id : uniqueIslands) {
                        potentialSize += islandSize[id]; // Sum up adjacent island sizes
                    }

                    maxIsland = max(maxIsland, potentialSize);
                }
            }
        }

        return maxIsland;
    }
};
