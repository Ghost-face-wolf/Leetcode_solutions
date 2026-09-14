class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        vector<vector<int>> rows=grid;
        vector<vector<int>> cols(n,vector<int>(n));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cols[i][j]=grid[j][i];
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;j++){
                if(rows[i]==cols[j]) count++;
            }
        }
        return count;
    }
};