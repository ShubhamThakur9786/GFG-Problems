/*
class Node {
  public:
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
    Node* reverse(Node* head) {
        Node* curr = head;
        Node* prev = NULL;
        while(curr) {
            Node* forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }
        return prev;
    }
    
    bool isIdentical(Node* h1, Node* h2) {
        while(h1 && h2) {
            if(h1->data != h2->data) return false;
            h1 = h1->next;
            h2 = h2->next;
        }
        return true; // enough since h2 <= h1 always here
    }

    bool isPalindrome(Node *head) {
        if(!head || !head->next) return true;

        Node* slow = head;
        Node* fast = head;

        // ✅ FIXED LOOP
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        Node* second = reverse(slow->next);
        slow->next = NULL;

        bool ans = isIdentical(head, second);

        return ans;
    }
};













