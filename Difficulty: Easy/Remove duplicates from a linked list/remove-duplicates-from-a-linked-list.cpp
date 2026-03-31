/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution {
  public:
    Node *removeDuplicates(Node *head) {
        // your code goes here
        unordered_set<int> hashSet;
        Node* curr = head;
        Node* prev = NULL;
        while(curr) {
            int data = curr->data;
            if(hashSet.find(data) != hashSet.end()) {
                //found data
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else {
                hashSet.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};