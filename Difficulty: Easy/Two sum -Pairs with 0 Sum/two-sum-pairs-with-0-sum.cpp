// User function template for C++

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        
        int left = 0;
        int right = arr.size()-1;
        
        while(left < right) {
            int sum = arr[left] + arr[right];
            
            if(sum == 0) {
                ans.push_back({arr[left], arr[right]});
                int currentLeft = arr[left];
                int currentRight = arr[right];
                
                while(left < right && arr[left] == currentLeft) {
                    left++;
                }
                while(left < right && arr[right] == currentRight) {
                    right--;
                }
            }
            else if(sum < 0) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return ans;
    }
};