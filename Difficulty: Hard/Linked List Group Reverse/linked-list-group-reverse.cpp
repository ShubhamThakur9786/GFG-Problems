/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head == NULL) return head;
        
        int count = 0;
        Node* prev = NULL;
        Node* next = NULL;
        Node* curr = head;
        while(count < k && curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next != NULL) {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};















