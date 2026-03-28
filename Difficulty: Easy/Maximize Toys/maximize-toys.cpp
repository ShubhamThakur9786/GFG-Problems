// User function Template for C++

class Solution {
  public:
    int toyCount(int N, int k, vector<int> arr) {
        // code here
        sort(arr.begin(), arr.end());  // sort prices
    
    int cnt = 0;
    
    for(int i = 0; i < N; i++) {
        if(arr[i] <= k) {
            k -= arr[i];
            cnt++;
        } else {
            break;  // no point checking further
        }
    }
    
    return cnt;
    }
};