class Solution {
  public:
    int sum(int n, int &add) {
        if(n == 0) {
            return 0;
        }
        add += n%10;
        return sum(n/10, add);
    }
    int sumOfDigits(int n) {
        // code here
        int add = 0;
        sum(n, add);
        return add;
    }
};