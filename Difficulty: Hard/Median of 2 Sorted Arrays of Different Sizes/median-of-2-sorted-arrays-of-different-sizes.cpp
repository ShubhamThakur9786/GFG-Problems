class Solution {
  public:
    double medianOf2(vector<int>& a, vector<int>& b) {
        int i = 0;
        int j = 0;
        vector<int> merged;
        
        while(i < a.size() && j < b.size()) {
            if(a[i] <= b[j]) {
                merged.push_back(a[i++]);
            }
            else {
                merged.push_back(b[j++]);
            }
        }
        
        while(i < a.size()) merged.push_back(a[i++]);
        while(j < b.size()) merged.push_back(b[j++]);
        
        int n = merged.size();
        
        if(n%2 == 0) {
            //even
            return (merged[n/2] + merged[n/2-1])/2.0;
        }
        else {
            return merged[n/2];
        }
    }
};