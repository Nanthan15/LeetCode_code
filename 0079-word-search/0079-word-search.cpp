class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));  // init visited matrix

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dfs(board, word, visited, 0, i, j)) return true;
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int idx, int x, int y) {
        if (idx == word.size()) return true;

        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size() ||
            board[x][y] != word[idx] || visited[x][y])
            return false;

        visited[x][y] = true;

        bool found = dfs(board, word, visited, idx + 1, x + 1, y) ||
                     dfs(board, word, visited, idx + 1, x - 1, y) ||
                     dfs(board, word, visited, idx + 1, x, y + 1) ||
                     dfs(board, word, visited, idx + 1, x, y - 1);

        visited[x][y] = false;  // backtrack

        return found;
    }
};
