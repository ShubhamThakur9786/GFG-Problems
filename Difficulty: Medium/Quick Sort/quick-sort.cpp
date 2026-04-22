class Solution {
  public:
    int partition(vector<int>& arr, int low, int high) {
        
        // code here
        int pivotelem = arr[high];
        int idx = low-1;
        for(int i=low; i<high; i++) {
            if(arr[i] < pivotelem) {
                idx++;
                swap(arr[idx], arr[i]);
            }
        }
        idx++;
        swap(arr[high], arr[idx]);
        return idx;
    }
    void quickSort(vector<int>& arr, int low, int high) {
        // code here
        if(low < high) {
            int pivotIdx = partition(arr, low, high);
            quickSort(arr, low, pivotIdx-1);
            quickSort(arr, pivotIdx+1, high);
        }
    }

  
};