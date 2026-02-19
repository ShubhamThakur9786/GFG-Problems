class Solution {
  public:
    void rearrange(vector<int> &arr) {
        // code here
        vector<int> pos;
        vector<int> neg;
        
        for(int x : arr) {
            if(x < 0) {
                neg.push_back(x);
            }
            else {
                pos.push_back(x);
            }
        }
        
        int i=0; 
        int j=0;
        int k=0;
        while(i < pos.size() && j < neg.size()) {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }
        
        while(i < pos.size()) {
            arr[k++] = pos[i++];
        }
        while(j < neg.size()) {
            arr[k++] = neg[j++];
        }
    }
};