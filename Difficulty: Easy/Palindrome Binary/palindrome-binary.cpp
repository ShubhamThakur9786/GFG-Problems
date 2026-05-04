class Solution {
  public:
    string calcBinary(int n) {
        string st = "";
        while(n) {
            int rem = n%2;
            st += rem;
            n = n/2;
        }
        
        reverse(st.begin(), st.end());
        return st;
    }
    
    bool checkBinary(string st) {
        int i=0;
        int j=st.size()-1;
        
        while(i<=j) {
            if(st[i] != st[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isBinaryPalindrome(int n) {
        // code here
        string strnum = calcBinary(n);
        
        bool ans = checkBinary(strnum);
        return ans;
    }
};