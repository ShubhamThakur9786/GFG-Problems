/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root, bool &balance) {
        if(root == NULL) return 0;
        int leftHt = height(root->left, balance);
        int rightHt = height(root->right, balance);
        if(leftHt - rightHt > 1 || leftHt - rightHt < -1) balance = false;
        
        return max(leftHt, rightHt) + 1;
    }
    bool isBalanced(Node* root) {
        // code here
        bool balance = true;
        height(root, balance);
        return balance;
    }
};