class Solution {
  public:
    void print(int n, int i) {
        if(i==n) {
            cout << i;
            return;
        }
        cout << i << " ";
        print(n, i+1);
        
    }
    void printNos(int n) {
        // Code here
        print(n, 1);
    }
};