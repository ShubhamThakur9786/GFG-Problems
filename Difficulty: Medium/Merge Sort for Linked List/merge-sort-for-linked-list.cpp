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
    Node* findMid(Node* temp) {
        Node* slow = temp;
        Node* fast = temp->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    Node* merge(Node* left, Node* right) {
        if(left == NULL) {
            return right;
        }
        if(right == NULL) {
            return left;
        }
        
        Node* ans = new Node(-1);
        Node* temp = ans;
        
        while(left && right) {
            if(left->data < right->data) {
                temp->next = left;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                temp = right;
                right = right->next;
            }
        }
        
        while(left) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        while(right) {
            temp->next = right;
            temp = right;
            right = right->next;
        }
        
        return ans->next;
    }
    
    Node* mergeSort(Node* head) {

        if(head == NULL || head->next == NULL) {
            return head;
        }
        
        Node* mid = findMid(head); 
        Node* left = head;
        Node* right = mid->next;
        mid->next = NULL;
        
        left = mergeSort(left);
        right = mergeSort(right);
        
        Node* result = merge(left, right);
        return result;
    }
};















