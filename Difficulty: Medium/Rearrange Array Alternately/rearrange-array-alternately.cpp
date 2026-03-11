class Solution {
  public:
    void rearrange(vector<int>& arr) {
         // Size of the array
        int n = arr.size();
        
        // Step 1: Sort the array in ascending order
        // Example: [1, 2, 3, 4, 5, 6]
        sort(arr.begin(), arr.end());
        
        // Index 'i' indicates the position where the next
        // maximum element will be placed
        int i = 0;
        
        // Loop runs for alternate positions (0, 2, 4, ...)
        while(i < n) {
            
            // Step 2: Store the current maximum element
            // Since array is sorted, last element is maximum
            int a = arr[n - 1];
            
            // Step 3: Shift elements one position to the right
            // from index 'i' to 'n-2' to make space for max element
            for(int j = n - 2; j >= i; j--) {
                arr[j+1] = arr[j];
            }
            
            // Step 4: Place the maximum element at index 'i'
            arr[i] = a;
            
            // Step 5: Move to next alternate position
            i += 2;
        }
    }
};