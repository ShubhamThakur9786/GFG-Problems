class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        vector<int> ans;
        int minAmt = 0;
        int maxAmt = 0;
        sort(prices.begin(), prices.end());
        
        int i=0;
        int j=prices.size()-1;
        while(i <= j) {
            minAmt += prices[i];
            i++;
            j-=k;
        }
        
        i=prices.size()-1;
        j=0;
        while(j <= i) {
            maxAmt += prices[i];
            i--;
            j += k;
        }
        
        ans.push_back(minAmt);
        ans.push_back(maxAmt);
        return ans;
    }
};