class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // code here
        stack<int> st;
        int n = mat.size();
        
        for(int i=n-1; i>=0; i--) {
            st.push(i);
        }
        
        while(st.size() > 1) {
            int first = st.top();
            st.pop();
            int second = st.top();
            st.pop();
            
            if(mat[first][second] == 1) {
                st.push(second);
            }
            else {
                st.push(first);
            }
        }
        
        if(st.empty()) return -1;
        
        int num = st.top();
        for(int i = 0; i < n; i++) {
            if(i != num) {
                // Celebrity should not know anyone
                if(mat[num][i] == 1) return -1;
                // Everyone should know celebrity
                if(mat[i][num] == 0) return -1;
            }
        }

        return num;
    }
};