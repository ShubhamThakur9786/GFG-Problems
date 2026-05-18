class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int st = 0;
        int end = arr.size()-1;
        int ans = 0;
        while(st <= end) {
            int mid = st + (end-st)/2;
            if(st == end) {
                ans = st;
            }
            if(arr[mid] < arr[end]) {
                end = mid;
            }
            else {
                st = mid+1;
            }
        }
        return ans;
    }
};
