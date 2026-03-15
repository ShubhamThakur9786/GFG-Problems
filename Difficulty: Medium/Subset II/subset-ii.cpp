class Solution {
  public:
    void subset(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int idx) {
        ans.push_back(temp);
        for(int i=idx; i<arr.size(); i++) {
            if(i>idx && arr[i] == arr[i-1]) continue;
            temp.push_back(arr[i]);
            subset(arr, ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> findSubsets(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> temp;
        int idx = 0;
        subset(arr, ans, temp, idx);
        return ans;
    }
};