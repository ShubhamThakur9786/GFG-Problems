class Solution {
  public:
    // Function to find all elements in array that appear more than n/k times.
    int countOccurence(vector<int>& arr, int k) {
        // Your code here
        
        int n = arr.size();
        int x = n/k;
        int ans = 0;
        unordered_map<int, int> mp;
        
        for(int num : arr) {
            mp[num]++;
        }
        
        for(auto it : mp) {
            if(it.second > x) {
                ans++;
            }
        }
        
        return ans;
    }
};