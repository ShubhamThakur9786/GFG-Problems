class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        unordered_map<int, int> mp;
        vector<int> ans;
        
        for(int i=0; i<arr.size(); i++) {
            mp[arr[i]]++;
        }
        
        for(auto x : mp) {
            if(x.second >= 2) {
                ans.push_back(x.first);
            }
        }
        
        return ans;
    }
};