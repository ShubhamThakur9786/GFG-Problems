class Solution {
  public:
    double power(double x, int n) {
        // code here
        double ans = 1.0;
        int N = n;
        if(n < 0) {
            N = -N;
        }
        
        while(N > 0) {
            if(N%2 == 0) {
                x = x*x;
                N = N/2;
            }
            else {
                ans = ans*x;
                N = N-1;
            }
        }
        
        if(n < 0) {
            ans = (double)(1.0)/(double)(ans);
        }
        return ans;
    }
};