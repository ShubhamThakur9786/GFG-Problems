// Final function implementation
class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int good = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] <= k) {
                good += 1;
            }
        }
        
        int bad = 0;
        for(int i=0; i<good; i++) {
            if(arr[i] > k) {
                bad += 1;
            }
        }
        
        int ans = bad;
        int i=0;
        int j=good;
        while(j < arr.size()) {
            if(arr[i] > k) bad--;
            if(arr[j] > k) bad++;
            ans = min(ans, bad);
            i++;
            j++;
        }
        return ans;
    }
};
