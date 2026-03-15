class Solution {
  public:
    bool palindrome(string& s, int st, int end) {
        if(st >= end) {
            return true;
        }
        if(s[st] != s[end]) {
            return false;
        }
        
        return palindrome(s, st+1, end-1);
        
    }
    bool isPalindrome(string& s) {
        // code here
        return palindrome(s,0,s.size()-1);
    }
};