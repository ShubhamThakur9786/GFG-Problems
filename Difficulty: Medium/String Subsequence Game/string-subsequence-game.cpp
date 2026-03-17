// User function Template for C++
class Solution {
  public:
    bool isVowel(char s) {
        return s=='a' || s=='e' || s=='i' || s=='o' || s=='u';
    }
    void solution(string &s, set<string> &ans, string &temp, int idx) {
        if(idx == s.size()) {
            if(!temp.empty() && isVowel(temp.front()) && !isVowel(temp.back())) {
                ans.insert(temp);
            }
            return;
        }
        
        //include
        temp.push_back(s[idx]);
        solution(s, ans, temp, idx+1);
        temp.pop_back();
        solution(s, ans, temp, idx+1);
    }
    set<string> allPossibleSubsequences(string S) {
        // code here
        set<string> ans;
        string temp;
        int idx = 0;
        solution(S, ans, temp, idx);
        return ans;
    }
};



















