/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* add(Node* temp1, Node* temp2) {
        
        Node* t1 = temp1;
        Node* t2 = temp2;
        Node* dummyNode = new Node(-1);
        Node* curr = dummyNode;
        int carry = 0;
        
        while(t1 || t2) {
            int sum = 0;
            if(t1) sum = sum + t1->data;
            if(t2) sum = sum + t2->data;
            if(carry) sum += carry;
            
            Node* newNode = new Node(sum%10);
            curr->next = newNode;
            curr = curr->next;
            
            carry = sum/10;
            
            if(t1) t1 = t1->next;
            if(t2) t2 = t2->next;
        }
        
        if(carry) {
            Node* newNode = new Node(carry);
            curr->next = newNode;
        }
        
        return dummyNode->next;
    }
    
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
    
        while(curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    
        return prev;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        
        Node* temp1 = reverse(head1);
        Node* temp2 = reverse(head2);
        
        
        Node* ans = reverse(add(temp1, temp2));
        while(ans->data == 0 && ans->next) {
            ans = ans->next;
        }
        return ans;
        
    }
};

















