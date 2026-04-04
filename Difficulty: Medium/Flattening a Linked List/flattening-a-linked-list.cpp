/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution {
  public:
    Node* mergeNode(Node* head1, Node* head2) {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        while(head1 && head2) {
            if(head1->data < head2->data) {
                temp->bottom = head1;
                temp = head1;
                head1 = head1->bottom;
            }
            else {
                temp->bottom = head2;
                temp = head2;
                head2 = head2->bottom;
            }
            temp->bottom = NULL;
            temp->next = NULL;
        }
        
        while(head1) {
            temp->bottom = head1;
            temp = head1;
            head1 = head1->bottom;
        }
        while(head2) {
            temp->bottom = head2;
            temp = head2;
            head2 = head2->bottom;
        }
        
        return dummyNode->bottom;
    }
    Node *flatten(Node *root) {
        // code here
        if(root == NULL) {
            return NULL;
        }
        
        Node* flattenNode = flatten(root->next);
        return mergeNode(root, flattenNode);
    }
};




