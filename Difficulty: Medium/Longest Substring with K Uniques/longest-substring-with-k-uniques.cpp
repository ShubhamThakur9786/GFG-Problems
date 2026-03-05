class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        int l=0;
        int r=0;
        
        unordered_map<char,int> mp;
        
        int maxi = -1;
        while(r<n)
        {
            mp[s[r]]++;
            while(mp.size()>k)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                {
                    mp.erase(s[l]);
                }
                l++;
            }
            
            if(mp.size() == k)
            maxi = max(r-l+1,maxi);
            
            r++;
        }
        
        return maxi;
    }
};