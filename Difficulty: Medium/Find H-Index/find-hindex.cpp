class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n = citations.size();
        vector<int> ans(n+1, 0);
        for(int i=0; i<citations.size(); i++) {
            if(citations[i] >= n) {
                ans[n]++;
            }
            else {
                ans[citations[i]]++;
            }
        }
        
        int count = 0;
        for(int i=n; i>=0; i--) {
            count += ans[i];
            if(count >= i) {
                return i;
            }
        }
        
        return 0;
    }
};