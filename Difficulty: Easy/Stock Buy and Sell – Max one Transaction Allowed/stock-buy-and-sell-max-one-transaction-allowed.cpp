class Solution {
  public:
    
    
    int maxProfit(vector<int> &prices) {
        // code here
        
        if(prices.size() < 2) return 0;
        int miniPrice = prices[0];
        int maxProfit = 0;
        
        for(int i=1; i<prices.size(); i++) {
            if(prices[i] < miniPrice) {
                miniPrice = prices[i];
            }
            else {
                maxProfit = max(maxProfit, prices[i]-miniPrice);
            }
        }
        
        return maxProfit;
    }
};
