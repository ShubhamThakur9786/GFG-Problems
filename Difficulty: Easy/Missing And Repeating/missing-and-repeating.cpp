class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        //missing number
        int n = arr.size();
    long long S = 0, S2 = 0;
    for(int i=0;i<n;i++){
        S += arr[i];
        S2 += (long long)arr[i]*arr[i];
    }
    long long S_n = (long long)n*(n+1)/2;
    long long S2_n = (long long)n*(n+1)*(2*n+1)/6;

    long long diff = S - S_n;           // R - M
    long long sum_diff = (S2 - S2_n)/diff; // R + M

    int R = (diff + sum_diff)/2;
    int M = R - diff;

    return {R, M};
    }
};