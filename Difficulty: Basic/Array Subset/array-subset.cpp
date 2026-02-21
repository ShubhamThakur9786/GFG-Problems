class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
        multiset<int> st(a.begin(), a.end());
        
        for(int x : b) {
            if(st.find(x) == st.end()) {
                return false;
            }
            st.erase(st.find(x));
        }
        
        return true;
    }
};