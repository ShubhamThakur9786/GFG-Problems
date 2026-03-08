class Solution {
  public:
    string firstNonRepeating(string &s) {
        queue<char> q;
        vector<int> freq(26, 0);
        string res = "";
    
        for(int i = 0; i < s.size(); i++) {
            
            freq[s[i] - 'a']++;
            q.push(s[i]);
    
            while(!q.empty() && freq[q.front() - 'a'] > 1) {
                q.pop();
            }
    
            if(q.empty()) {
                res += '#';
            }
            else {
                res += q.front();
            }
        }
    
        return res;
    }
};