class Solution {
  public:
    void insertionSort(vector<int>& arr) {
        // code here
        for(int i=1; i<arr.size(); i++) {
            int j=i;
            while(j > 0 && arr[j] < arr[j-1]) {
                swap(arr[j], arr[j-1]);
                j--;
            }
        }
    }
};