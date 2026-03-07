// User function Template for C++

class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        int ans = 0;
        priority_queue<int> maxHeap; 
        for(int i=0; i<arr.size(); i++) {
            maxHeap.push(arr[i]);
        }
        
        while(k--) {
            int elem = maxHeap.top();
            ans += elem;
            maxHeap.pop();
            elem--;
            if(elem) {
                maxHeap.push(elem);
            }
        }
        
        return ans;
    }
};