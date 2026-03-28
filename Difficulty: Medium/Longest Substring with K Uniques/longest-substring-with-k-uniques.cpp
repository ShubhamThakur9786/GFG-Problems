class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        
        int n = s.size();
        int j=0;
        int i=0;
        unordered_map<char,int> mp;
        int ans = -1;
        
        while(j < n) {
            mp[s[j]]++;
            if(mp.size() < k) {
                j++;
            }
            else if(mp.size() == k) {
                ans = max(ans, j-i+1);
                j++;
            }
            else {
                while(mp.size() > k && i < j) {
                    mp[s[i]]--;
                    if(mp[s[i]] == 0) mp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};



















