class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        
        int r[] = {0,1,0,-1};
        int c[] = {-1,0,1,0};
        
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<int>> dist(n, vector<int>(m, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    q.push({{i, j}, 0});
                    vis[i][j] = true;
                }
            }
        }
        
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dst = q.front().second;
            q.pop();
            dist[row][col] = dst;
            
            for(int i=0; i<4; i++) {
                int nrow = row + r[i];
                int ncol = col + c[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0) {
                    vis[nrow][ncol] = true;
                    q.push({{nrow, ncol}, dst+1});
                }
            }
        }
        
        return dist;
        
    }
};