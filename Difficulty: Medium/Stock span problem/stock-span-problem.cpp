class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        int n = arr.size();
        stack<int> st;
        vector<int> ans(n, 1);
        
        for(int i=0; i<arr.size(); i++) {
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }
            
            if(st.empty()) {
                ans[i] = i+1;
            }
            else {
                ans[i] = i-st.top();
            }
            
            st.push(i);
        }
        
        return ans;
    }
};