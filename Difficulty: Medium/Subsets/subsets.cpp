class Solution {
  public:
    void subset(vector<int>& arr, vector<vector<int>> &ans, vector<int> &temp, int idx) {
        if(idx == arr.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(arr[idx]);
        subset(arr, ans, temp, idx+1);
        temp.pop_back();
        subset(arr, ans, temp, idx+1);
    }
    vector<vector<int>> subsets(vector<int>& arr) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        subset(arr, ans, temp, idx);
        sort(ans.begin(), ans.end());
        return ans;
    }
};