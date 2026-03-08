class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        // vector<int> ans;
        // int i=0;
        // int j=0;
        // int n = arr.size();
        
        // while(j < n) {
        //     if(j-i+1 < k) {
        //         j++;
        //     }
        //     else if(j-i+1 == k) {
        //         for(int st=i; st<i+k; st++) {
        //             if(arr[st] < 0) {
        //                 ans.push_back(arr[st]);
        //                 break;
        //             }
        //             if(st==i+k-1) {
        //                 ans.push_back(0);
        //             }
        //         }
        //         i++;
        //         j++;
        //     }
        // }
        
        // return ans;
        
        //optimize;
        queue<int> q;
        vector<int> ans;
        int i=0;
        int j=0;
        while(j < arr.size()) {
            if(arr[j] < 0) {
                q.push(j);
            }
            
            if(j-i+1 < k) {
                j++;
            }
            else if(j-i+1 == k) {
                while(!q.empty() && q.front() < i) {
                    q.pop();
                }
                if(q.empty()) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(arr[q.front()]);
                }
                i++;
                j++;
            }
        }
        
        return ans;
    }
};






















