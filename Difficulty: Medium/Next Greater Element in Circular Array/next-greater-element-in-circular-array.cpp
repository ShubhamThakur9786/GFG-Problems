class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i=0; i<2*n; i++) {
            int idx = i%n;
            while(!st.empty() && arr[idx] > arr[st.top()]) {
                ans[st.top()] = arr[idx];
                st.pop();
            }
            
            if(i < n) {
                st.push(idx);
            }
        }
        
        return ans;
    }
};


// // code here
        // stack<int> st;
        // vector<int> ans(arr.size(), -1);
        
        // for(int i=0; i<arr.size(); i++) {
        //     while(!st.empty() && arr[i] > arr[st.top()]) {
        //         ans[st.top()] = arr[i];
        //         st.pop();
        //     }
        //     st.push(i);
        // }
        
        
        // return ans;