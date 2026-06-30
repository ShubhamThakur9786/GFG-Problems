class Solution {
  public:
    void dfs(int node, vector<vector<int>> &adjls, vector<bool> &vis, stack<int> &st) {
        vis[node] = true;
        
        for(auto adjnode : adjls[node]) {
            if(!vis[adjnode]) {
                dfs(adjnode, adjls, vis, st);
            }    
        }
        
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adjls(V);
        
        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            
            adjls[u].push_back(v);
        }
        
        vector<bool> vis(V, false);
        stack<int> st;
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                dfs(i, adjls, vis, st);
            }
        }
        
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
        
    }
};