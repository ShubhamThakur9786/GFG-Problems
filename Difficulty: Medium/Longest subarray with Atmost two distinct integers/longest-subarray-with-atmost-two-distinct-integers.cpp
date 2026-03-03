class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        int left = 0;
        unordered_map<int, int> freq;
        int maxSize = 0;
        
        for(int right = 0; right < arr.size(); right++) {
            freq[arr[right]]++;
            
            while(freq.size() > 2) {
                freq[arr[left]]--;
                if(freq[arr[left]] == 0) {
                    freq.erase(arr[left]);
                }
                left++;
            }
            
            maxSize = max(maxSize, right-left+1);
        }
        
        return maxSize;
    }
};