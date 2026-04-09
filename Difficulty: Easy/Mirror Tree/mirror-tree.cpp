/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if(root == NULL) {
            return;
        }
        Node* left = root->left;
        root->left = root->right;
        root->right = left;
        
        if(root->left) {
            mirror(root->left);
        }
        if(root->right) {
            mirror(root->right);
        }
    }
};