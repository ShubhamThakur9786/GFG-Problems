/* Structure for tree and linked list
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node()
        : data(0)
        , left(NULL)
        , right(NULL) {}

    Node(int x)
        : data(x)
        , left(NULL)
        , right(NULL) {}
};
 */

// This function should return head to the DLL
class Solution {
  public:
    void convertIntoArray(Node* root, vector<int> &arr) {
        if(!root) return;
        
        convertIntoArray(root->left, arr);
        arr.push_back(root->data);
        convertIntoArray(root->right, arr);
    }
    Node* bToDLL(Node* root) {
        // code here
        vector<int> arr;
        convertIntoArray(root, arr);
        
        Node* head = new Node(arr[0]);
        Node* curr = head;
        Node* prev = NULL;
        
        for(int i=1; i<arr.size(); i++) {
            Node* temp = new Node(arr[i]);
            curr->right = temp;
            temp->left = curr;
            curr = temp;
        }
        
        return head;
    }
};











