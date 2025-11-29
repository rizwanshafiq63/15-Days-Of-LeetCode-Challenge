class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));
        
        // directions: up, down, left, right
        vector<int> dirs = {1, 0, -1, 0, 1};
        
        function<void(int,int,vector<vector<bool>>&)> dfs = [&](int r, int c, vector<vector<bool>>& visited) {
            visited[r][c] = true;
            for (int k = 0; k < 4; k++) {
                int nr = r + dirs[k], nc = c + dirs[k+1];
                if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
                if (visited[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue;
                dfs(nr, nc, visited);
            }
        };
        
        // Pacific (top row, left column)
        for (int c = 0; c < n; c++) dfs(0, c, pac);
        for (int r = 0; r < m; r++) dfs(r, 0, pac);
        
        // Atlantic (bottom row, right column)
        for (int c = 0; c < n; c++) dfs(m-1, c, atl);
        for (int r = 0; r < m; r++) dfs(r, n-1, atl);
        
        vector<vector<int>> result;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pac[r][c] && atl[r][c])
                    result.push_back({r, c});
            }
        }
        return result;
    }
};
