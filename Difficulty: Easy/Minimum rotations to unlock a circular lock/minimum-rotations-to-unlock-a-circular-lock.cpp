// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        // code here
        long long ans = 0;
        int diff = 0;
        while(R || D) {
            int r = R%10;
            int d = D%10;
            diff = abs(r-d);
            ans += min(diff, 10-diff);
            R = R/10;
            D = D/10;
        }
        
        return ans;
        
    }
};