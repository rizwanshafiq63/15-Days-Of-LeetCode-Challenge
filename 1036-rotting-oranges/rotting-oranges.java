class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length, n = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int fresh = 0;

        // Step 1: Add all rotten oranges to the queue, count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    queue.offer(new int[]{i, j, 0}); // {row, col, minute}
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // If no fresh oranges, answer is 0
        if (fresh == 0) return 0;

        int minutes = 0;
        int[][] dirs = {{1,0},{-1,0},{0,1},{0,-1}};

        // Step 2: BFS
        while (!queue.isEmpty()) {
            int[] cur = queue.poll();
            int r = cur[0], c = cur[1], time = cur[2];
            minutes = Math.max(minutes, time);

            for (int[] d : dirs) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2; // rot it
                    fresh--;
                    queue.offer(new int[]{nr, nc, time + 1});
                }
            }
        }

        // If fresh oranges remain, impossible
        return fresh == 0 ? minutes : -1;
    }
}
