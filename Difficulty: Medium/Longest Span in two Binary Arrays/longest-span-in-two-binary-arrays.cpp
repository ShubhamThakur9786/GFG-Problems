class Solution {
  public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        // code here
        unordered_map<int, int> mp;
        
        int maxLen = 0;
        int prefixSum = 0;
        
        for(int i=0; i<a1.size(); i++) {
            prefixSum += a1[i] - a2[i];
            
            if(prefixSum == 0) {
                maxLen = i+1;
            }
            
            if(mp.find(prefixSum) != mp.end()) {
                maxLen = max(maxLen, i-mp[prefixSum]);
            }
            else {
                mp[prefixSum] = i;
            }
        }

        return maxLen;
    }
};