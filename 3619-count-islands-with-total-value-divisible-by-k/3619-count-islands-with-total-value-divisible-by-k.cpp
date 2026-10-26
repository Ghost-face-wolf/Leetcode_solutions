class Solution {
private:
    long long dfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Add current cell value and mark as visited by resetting to 0
        long long current_sum = grid[r][c];
        grid[r][c] = 0;
        
        // 4-directional offsets: up, right, down, left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > 0) {
                current_sum += dfs(nr, nc, grid);
            }
        }
        
        return current_sum;
    }

public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int valid_islands_count = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0) {
                    // Found a new island, calculate its total value using DFS
                    long long island_total = dfs(i, j, grid);
                    
                    // Check if total value is divisible by k
                    if (island_total % k == 0) {
                        valid_islands_count++;
                    }
                }
            }
        }
        
        return valid_islands_count;
    }
};