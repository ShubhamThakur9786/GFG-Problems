class Solution {
  public:
  
    void solution(string &s, vector<string> &ans, int idx, string &temp) {
        if(idx == s.size()) {
            ans.push_back(temp);
            return;
        }
        //include
        temp.push_back(s[idx]);
        solution(s, ans, idx+1, temp);
        temp.pop_back();
        solution(s, ans, idx+1, temp);
    }
    vector<string> AllPossibleStrings(string s) {
        // Code here
        //include or exclude
        vector<string> ans;
        string temp;
        int idx = 0;
        solution(s, ans, idx, temp);
        sort(ans.begin(), ans.end());
        return ans;
    }
};