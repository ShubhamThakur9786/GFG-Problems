/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

class Solution {
  public:
    // Function to remove duplicates from sorted linked list.
    Node* removeDuplicates(Node* &head) {

        // code here
        Node* curr = head;
        while(curr != NULL && curr->next != NULL) {
            if(curr->data == curr->next->data) {
                Node* nexttonext = curr->next->next;
                curr->next = nexttonext;
            }
            else {
                curr = curr->next;
            }
        }
        return head;
    }
};