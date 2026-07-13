class Solution {
  public:
    void solve(vector<vector<int>>& adj, vector<bool> &vis, int node, vector<int> &ans) {
        ans.push_back(node);
        vis[node] = true;
        
        for(auto it : adj[node]) {
            if(!vis[it]) {
                solve(adj, vis, it, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<bool> vis(n, false);
        solve(adj, vis, 0, ans);
        
        return ans;
    }
};