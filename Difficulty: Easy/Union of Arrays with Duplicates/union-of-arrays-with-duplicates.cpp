class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {
        // code here
        unordered_set<int> st(a.begin(), a.end());
        
        int i=0;
        while(i<b.size()) {
            st.insert(b[i]);
            i++;
        }
        
        
        return vector<int>(st.begin(), st.end());
    }
};