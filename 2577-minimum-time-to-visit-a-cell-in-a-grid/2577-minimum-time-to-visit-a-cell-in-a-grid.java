class Solution {
    public int minimumTime(int[][] grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        
        int m = grid.length, n = grid[0].length;
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        boolean[][] vis = new boolean[m][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0]-b[0]);
        pq.add(new int[]{0, 0, 0});
        
        while (!pq.isEmpty()) {
            int[] curNode = pq.poll();
            int time = curNode[0], curRow = curNode[1], curCol = curNode[2];
            
            if (curRow == m - 1 && curCol == n - 1) return time;
            if (vis[curRow][curCol]) continue;
            vis[curRow][curCol] = true;
            
            for (int[] dir : dirs) {
                int nextRow = curRow + dir[0], nextCol = curCol + dir[1];
                if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n || vis[nextRow][nextCol]) continue;
                int cycleType = ((grid[nextRow][nextCol] - time) % 2 == 0) ? 1 : 0;
                pq.add(new int[]{Math.max(grid[nextRow][nextCol] + cycleType, time + 1), nextRow, nextCol});
            }
        }
        return -1;
    }
}