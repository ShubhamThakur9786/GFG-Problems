class Solution {
  public:
    
    int mergeSortCount(vector<int> &arr, int st, int mid, int end) {
        vector<int> temp;
        int i=st;
        int j=mid+1;
        long long invCount = 0;
        
        while(i <= mid && j <= end) {
            if(arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
                invCount += (mid-i+1);
            }
        }
        
        while(i <= mid) {
            temp.push_back(arr[i++]);
        }
        while(j <= end) {
            temp.push_back(arr[j++]);
        }
        
        for(int i=st; i<=end; i++) {
            arr[i] = temp[i-st];
        }
        
        return invCount;
    }
    
    int mergeSort(vector<int> &arr, int st, int end) {
        long long invCount = 0;
        if(st < end) {
            int mid = st+(end-st)/2;
            invCount += mergeSort(arr, st, mid);
            invCount += mergeSort(arr, mid+1, end);
            invCount += mergeSortCount(arr, st, mid, end);
        }
        
        return invCount;
    }
    
    int inversionCount(vector<int> &arr) {
        // Code Here
        return mergeSort(arr, 0, arr.size()-1);
    }
};