class Solution {
  public:
    int stockBuySell(vector<int> &arr) {
        // code here
        int prev = arr[0];
        int maxProfit = 0;
        
        for(int i=1; i<arr.size(); i++) {
            if(arr[i] > prev) {
                maxProfit += (arr[i]-prev);
            }
            prev = arr[i];
        }
        
        return maxProfit;
    }
};