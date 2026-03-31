/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* FCD(Node* head) {
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast) {
                return slow;
            }
        }
        
        return NULL;
    }
    void removeLoop(Node* head) {
        // code here
        Node* prev = NULL;
        Node* intersection = FCD(head);
        if(intersection == NULL) {
            return;
        }
        Node* slow = head;
        
        if(slow == intersection) {
            while(intersection->next != slow) {
                intersection = intersection->next;
            }
            intersection->next = NULL;
            return;
        }
        
        while(slow != intersection) {
            prev = intersection;
            intersection = intersection->next;
            slow = slow->next;
        }
        
        prev->next = NULL;
    }
};