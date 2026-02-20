class Solution {
    static bool cmp(string first, string second) {
        if(first+second > second+first) {
            return true;
        }
        else {
            return false;
        }
    }
    public: 
    string findLargest(vector<int> &arr) {
        vector<string> ans;
        
        for(int x : arr) {
            ans.push_back(to_string(x));
        }
        
        
        sort(ans.begin(), ans.end(), cmp);
        
        //important case if all of the element in ans is 0
        if(ans[0] == "0") {
            return "0";
        }
        string result = "";
        
        for(auto x : ans) {
            result += x;
        }
        
        return result;
    }
};