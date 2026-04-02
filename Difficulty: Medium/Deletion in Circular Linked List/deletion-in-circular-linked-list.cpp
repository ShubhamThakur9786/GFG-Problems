/*
class Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* deleteNode(Node* head, int key) {
    // case 1: empty list
    if(head == NULL) return NULL;

    Node* curr = head;
    Node* prev = NULL;

    // case 2: single node
    if(head->next == head) {
        if(head->data == key) {
            delete head;
            return NULL;
        }
        return head;
    }

    // case 3: deleting head
    if(head->data == key) {
        Node* tail = head;

        // find last node
        while(tail->next != head) {
            tail = tail->next;
        }

        Node* temp = head;
        head = head->next;
        tail->next = head;

        delete temp;
        return head;
    }

    // case 4: delete non-head node
    prev = head;
    curr = head->next;

    while(curr != head) {
        if(curr->data == key) {
            prev->next = curr->next;
            delete curr;
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    // case 5: key not found
    return head;
}
};