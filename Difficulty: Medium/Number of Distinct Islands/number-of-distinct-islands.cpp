class Solution {
  public:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<bool>> &vis,
    vector<pair<int, int>> &temp, int row0, int col0) {
        
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = true;
        temp.push_back({row-row0, col-col0});
        int r[] = {0, 1, 0, -1};
        int c[] = {-1, 0, 1, 0};
            
        for(int i=0; i<4; i++) {
            int nrow = r[i] + row;
            int ncol = c[i] + col;
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 'L' &&
                !vis[nrow][ncol]) {
                    dfs(nrow, ncol, grid, vis, temp, row0, col0);
                }
        }
    }
    int countDistinctIslands(vector<vector<char>>& grid) {
        // code here
        set<vector<pair<int, int>>> st;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'L' && !vis[i][j]) {
                    vector<pair<int, int>> temp;
                    dfs(i, j, grid, vis, temp, i, j);
                    st.insert(temp);
                }
            }
        }
        return st.size();
    }
};




