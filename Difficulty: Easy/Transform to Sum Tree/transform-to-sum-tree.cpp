/* A binary tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    int solve(Node* &node) {
        if(!node) return 0;
        
        int leftSum = solve(node->left);
        int rightSum = solve(node->right);
        
        int oldVal = node->data;
        node->data = leftSum+rightSum;
        
        return oldVal + node->data;
    }
    void toSumTree(Node *node) {
        // code here
        solve(node);
    }
};