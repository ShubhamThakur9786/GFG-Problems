class Solution {
  public:
    bool isSafe(int x, int y, vector<vector<int>>& maze, vector<vector<bool>> &vis) {
        if((x >= 0 && x < maze.size()) && (y >= 0 && y < maze.size()) && 
            maze[x][y] == 1 && vis[x][y] == 0) {
                return true;
            }
            return false;
    }
    void solve(vector<vector<int>>& maze, int x, int y, vector<vector<bool>> &vis,
    vector<string> &ans, string path) {
        
        if(x == maze.size()-1 && y == maze.size()-1) {
            ans.push_back(path);
            return;
        }
        
        vis[x][y] = 1;
        
        //down
        if(isSafe(x+1, y, maze, vis)) {
            path.push_back('D');
            solve(maze, x+1, y, vis, ans, path);
            path.pop_back();
        }
        
        //left
        if(isSafe(x, y-1, maze, vis)) {
            path.push_back('L');
            solve(maze, x, y-1, vis, ans, path);
            path.pop_back();
        }
        
        //right
        if(isSafe(x, y+1, maze, vis)) {
            path.push_back('R');
            solve(maze, x, y+1, vis, ans, path);
            path.pop_back();
        }
        
        //up
        if(isSafe(x-1, y, maze, vis)) {
            path.push_back('U');
            solve(maze, x-1, y, vis, ans, path);
            path.pop_back();
        }
        
        vis[x][y] = 0;
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
            vector<string> ans;
        if(maze[0][0] == 0) {
            return ans;
        }
        int n = maze.size();
        int m = maze[0].size();
        
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        
        int srcx = 0;
        int srcy = 0;
        

        string path = "";
        
        solve(maze, srcx, srcy, vis, ans, path);
        sort(ans.begin(), ans.end());
        return ans;
        
    }
};