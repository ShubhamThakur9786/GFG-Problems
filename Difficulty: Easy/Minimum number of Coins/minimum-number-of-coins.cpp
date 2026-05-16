class Solution {
  public:
    int findMin(int n) {
        // code here
        vector<int> arr = {10,5,2,1};
        int i=0;
        int notes = 0;
        int ans = 0;
        while(n) {
            notes = n/arr[i];
            if(notes) {
                ans += notes;
            }
            n = n%arr[i];
            i++;
        }
        return ans;
    }
};