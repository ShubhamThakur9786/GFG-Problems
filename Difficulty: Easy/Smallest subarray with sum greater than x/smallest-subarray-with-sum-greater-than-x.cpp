class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int i=0;
        int j=0;
        int sum = 0;
        int ans = INT_MAX;
        
        while(j<arr.size()) {
            sum += arr[j];
            while(sum > x) {
                ans = min(j-i+1, ans);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        
        if(ans == INT_MAX) return 0;
        
        return ans;
    }
};