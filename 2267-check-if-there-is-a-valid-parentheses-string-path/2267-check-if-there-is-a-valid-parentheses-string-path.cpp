class Solution {
    int m,n;
    bool visited[100][100][101];
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        if((m+n-1)%2!=0) return false;
        if(grid[0][0]==')'||grid[m-1][n-1]=='(') return false;
        return dfs(grid,0,0,0);
    }
private:
    bool dfs(vector<vector<char>>& grid, int r, int c, int balance){
        if(grid[r][c]=='(') balance++;
        else balance--;
        if(balance<0||balance>(m-r+n-c-1)) return false;
        if(r==m-1&&c==n-1) return balance==0;
        if(visited[r][c][balance]) return false;
        visited[r][c][balance]=true;
        if(c+1<n&&dfs(grid,r,c+1,balance)) return true;
        if(r+1<m&&dfs(grid,r+1,c,balance)) return true;
        return false;
    }
};