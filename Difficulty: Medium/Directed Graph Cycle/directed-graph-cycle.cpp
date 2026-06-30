class Solution {
  public:
    bool dfs(int i, vector<vector<int>> adjls, vector<bool> &vis, vector<int> &pathVis) {
        vis[i] = true;
        pathVis[i] = 1;
        
        for(auto adjnode : adjls[i]) {
            if(!vis[adjnode]) {
                if(dfs(adjnode, adjls, vis, pathVis)) {
                    return true;
                }
            }
            else if(pathVis[adjnode] == 1) {
                return true;
            }
        }
        
        pathVis[i] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjls(V);
        
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adjls[u].push_back(v);
        }
        
        vector<bool> vis(V, false);
        vector<int> pathVis(V, 0);
        
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                if(dfs(i, adjls, vis, pathVis) == true) {
                    return true;
                }
             }
        }
        return false;
    }
};