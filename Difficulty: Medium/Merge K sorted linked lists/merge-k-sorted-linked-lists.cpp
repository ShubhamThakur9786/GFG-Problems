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
    struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->data > b->data;
    }
};

Node* mergeKLists(vector<Node*>& arr) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (Node* head: arr) {
        if (head) pq.push(head);
    }

    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (!pq.empty()) {
        Node* top = pq.top();
        pq.pop();

        tail->next = top;
        tail = top;

        if (top->next) {
            pq.push(top->next);
        }
    }

    tail->next = NULL; // good practice

    return dummy->next;
}
};