/*
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};
*/

class Solution {
  public:
    Node *rotateDLL(Node *head, int p) {

    if (head == NULL || p == 0) return head;

    // Step 1: Find length
    int len = 0;
    Node* temp = head;
    while (temp) {
        len++;
        temp = temp->next;
    }

    // Step 2: Reduce p
    p = p % len;
    if (p == 0) return head;

    // Step 3: Move to p-th node
    Node* curr = head;
    int i = 1;
    while (i < p) {
        curr = curr->next;
        i++;
    }

    Node* pthNode = curr;
    Node* newHead = pthNode->next;

    // Break
    newHead->prev = NULL;
    pthNode->next = NULL;

    // Go to end
    Node* tail = newHead;
    while (tail->next) {
        tail = tail->next;
    }

    // Attach
    tail->next = head;
    head->prev = tail;

    return newHead;
}
};














