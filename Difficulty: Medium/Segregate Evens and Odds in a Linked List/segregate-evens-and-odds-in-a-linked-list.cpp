// User function template for C++

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
    Node* divide(Node* head) {
        // code here
        Node* evenList = new Node(-1);
        Node* evenHead = evenList;
        Node* oddList = new Node(-1);
        Node* oddHead = oddList;
        
        while(head) {
            Node* newNode = new Node(head->data);
            if(head->data % 2 == 0) {
                evenList->next = newNode;
                evenList = newNode;
            }
            else {
                oddList->next = newNode;
                oddList = newNode;
            }
            head = head->next;
        }
        
        evenList->next = oddHead->next;
        oddList->next = NULL;
        
        return evenHead->next;
    }
};