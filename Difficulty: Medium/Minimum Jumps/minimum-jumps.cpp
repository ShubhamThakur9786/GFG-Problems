class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int maxIdx = 0;
        int choice = 0;
        int jump = 0;
        
        for(int i=0; i<arr.size()-1; i++) {
            maxIdx = max(maxIdx,i+arr[i]);
            if(i == choice) {
                choice = maxIdx;
                jump++;
            }
        }
        
        if(choice >= arr.size()-1) return jump;
        
        return -1;
    }
};
