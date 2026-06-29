class Solution {
  public:
  
    bool check(int start, int V, vector<vector<int>> &edges, vector<int> &color) {
        queue<int> q;
        q.push(start);
        color[start] = 0;
        
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            int iniColor = color[top];
            
            for(auto node : edges[top]) {
                if(color[node] == -1) {
                    q.push(node);
                    color[node] = !iniColor;
                }
                else {
                    if(color[node] == iniColor) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int> color(V, -1);
        vector<vector<int>> adjls(V);
        
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
        
            adjls[u].push_back(v);
            adjls[v].push_back(u);
        }
        
        for(int i=0; i<V; i++) {
            if(color[i] == -1) {
                if(!check(i, V, adjls, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};