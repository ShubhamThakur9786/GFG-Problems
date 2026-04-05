/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    int getKthFromLast(Node* head, int k) {
        // code here
        Node* temp = head;
        int len = 0;
        while(temp) {
            temp = temp->next;
            len++;
        }
        
        if(len < k) return -1;
        
        temp = head;
        for(int i=0; i<len-k; i++) {
            temp = temp->next;
        }
        
        return temp->data;
    }
};