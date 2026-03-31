/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        
        while(curr) {
            Node* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        
        return prev;
    }
    Node* addOne(Node* head) {
        // Your Code here
        head = reverse(head);
        Node* temp = head;
        int carry = 1;
        while(temp) {
            temp->data = temp->data + carry;
            if(temp->data < 10) {
                carry = 0;
                break;
            }
            else {
                carry = 1;
                temp->data = 0;
            }
            temp = temp->next;
        }
        
        head = reverse(head);
        if(carry) {
            Node* newnode = new Node(1);
            newnode->next = head;
            return newnode;
        }
        else {
            return head;
        }
    }
    
};













