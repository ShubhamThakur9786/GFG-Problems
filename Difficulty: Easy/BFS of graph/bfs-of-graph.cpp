class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int size = adj.size();
        vector<bool> vis(size, false);
        queue<int> q;
        q.push(0);
        vis[0] = true;
        vector<int> bfs;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it : adj[node]) {
                if(!vis[it]) {
                    vis[it] = true;
                    q.push(it);
                }
            }
        }
        return bfs;
    }
};