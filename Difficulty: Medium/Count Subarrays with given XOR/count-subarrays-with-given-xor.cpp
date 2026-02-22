class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int prexor = 0;
        int count = 0;
        unordered_map<int, int> mp;
        for(int i=0; i<arr.size(); i++) {
            prexor ^= arr[i];
            if(prexor == k) {
                count++;
            }
            if(mp.find(prexor^k) != mp.end()) {
                count += mp[prexor^k];
            }
            mp[prexor]++;
        }
        
        return count;
    }
};