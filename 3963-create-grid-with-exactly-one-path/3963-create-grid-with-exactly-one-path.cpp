class Solution {
public:
    vector<string> createGrid(int m, int n) {
        // Initialize an m x n grid filled with obstacles '#'
        vector<string> g(m, string(n, '#'));
        
        // Fill the first row entirely with '.'
        g[0] = string(n, '.');
        
        // Fill the last column of every row with '.'
        for (int i = 0; i < m; ++i) {
            g[i][n - 1] = '.';
        }
        
        return g;
    }
};