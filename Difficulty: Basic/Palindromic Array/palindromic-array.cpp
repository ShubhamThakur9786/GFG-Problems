/*Complete the function below*/

class Solution {
  public:
    bool isPalin(int n) {
        string num = to_string(n);
        int len = num.size();
        
        int r = len-1;
        int l = 0;
        while(l <= r) {
            if(num[l] != num[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    bool isPalinArray(vector<int> &arr) {
        // code here
        for(int i=0; i<arr.size(); i++) {
            if(!isPalin(arr[i])) {
                return false;
            }
        }
        
        return true;
    }
};