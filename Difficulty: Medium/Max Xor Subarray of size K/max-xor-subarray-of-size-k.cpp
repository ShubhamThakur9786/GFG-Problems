class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
        
         int n = arr.size();
    
    if (k > n) return 0;

    int currXor = 0;

    // Compute XOR of first k elements
    for (int i = 0; i < k; i++) {
        currXor ^= arr[i];
    }

    int maxXor = currXor;

    // Slide the window
    for (int i = k; i < n; i++) {
        // Remove leftmost element
        currXor ^= arr[i - k];

        // Add new element
        currXor ^= arr[i];

        maxXor = max(maxXor, currXor);
    }

    return maxXor;
    }
};