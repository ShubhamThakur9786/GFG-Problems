/*

The structure of linked list is the following

struct Node
{
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
    Node *compute(Node *head) {
        // your code goes here
        Node* revHead = reverse(head);

        // Step 2: Remove nodes smaller than max so far
        Node* curr = revHead;
        int maxi = curr->data;
    
        Node* temp = curr;
    
        while(curr && curr->next) {
            if(curr->next->data < maxi) {
                // delete node
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxi = curr->data;
            }
        }
    
        // Step 3: Reverse back
        return reverse(revHead);
    }
};













