// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        // code here
        priority_queue<int, vector<int>, greater<int>> minHeap;
        DLLNode* temp1 = head;
        DLLNode* temp2 = head;
        while(temp1) {
            minHeap.push(temp1->data);
            if(minHeap.size() == k+1) {
                temp2->data = minHeap.top();
                temp2 = temp2->next;
                minHeap.pop();
            }
            temp1 = temp1->next;
        }
        
        while(!minHeap.empty()) {
            temp2->data = minHeap.top();
            minHeap.pop();
            temp2 = temp2->next;
        }
        return head;
    }
};











