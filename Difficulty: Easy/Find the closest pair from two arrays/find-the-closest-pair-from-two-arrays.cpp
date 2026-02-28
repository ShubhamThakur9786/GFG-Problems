class Solution {
  public:
    vector<int> findClosestPair(vector<int> &arr1, vector<int> &arr2, int x) {
        // code here
        int l = 0;
        int r = arr2.size()-1;
        int minDiff = INT_MAX;
        vector<int> ans;
        
        while(l < arr1.size() && r >= 0) {
            int sum = arr1[l] + arr2[r];
            
            if(minDiff > abs(sum-x)) {
                minDiff = abs(sum-x);
                ans = {arr1[l], arr2[r]};
            }
            if(sum < x) {
                l++;
            }
            else if(sum > x) {
                r--;
            }
            else {
                return {arr1[l], arr2[r]};
            }
        }
        
        return ans;
    }
};