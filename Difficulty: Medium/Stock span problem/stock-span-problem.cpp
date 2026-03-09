class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        // code here
        
        stack<int> st; //store indices
        vector<int> ans(arr.size());
        for(int i=0; i<arr.size(); i++) {
            int span = 1;
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