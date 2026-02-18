class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int, int> mp;
        int count = 0;
        
        for(int i=0; i<arr.size(); i++) {
            int elem = target-arr[i];
            if(mp.find(elem) != mp.end()) {
                count += mp[elem];
            }
            mp[arr[i]]++;
        }
        
        return count;
    }
};