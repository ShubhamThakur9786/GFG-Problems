class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        int n = edges.size();
        vector<vector<int>> adjls(V);
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adjls[u].push_back(v);
            adjls[v].push_back(u);
        }
        
        vector<bool> vis(V, false);
        
       for(int i=0; i<V; i++) {
            if(vis[i]) continue;
            queue<pair<int, int>> q;

            
            q.push({i, -1});
            vis[i] = true;
            
            while(!q.empty()) {
                auto top = q.front();
                int node = top.first;
                int parent = top.second;
                q.pop();
                
                for(auto it : adjls[node]) {
                    if(!vis[it]) {
                        vis[it] = true;
                        q.push({it, node});
                    }
                    else if(it != parent) {
                        return true;
                    }
                }
            }
       }
        return false;
        
    }
};