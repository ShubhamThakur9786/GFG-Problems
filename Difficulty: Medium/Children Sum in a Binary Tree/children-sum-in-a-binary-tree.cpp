/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool isSum(Node* root) {
        if(root == NULL) {
            return true;
        }
        if(!root->left && !root->right) {
            //leaf
            return true;
        }
    
        int rootVal = root->data;
        int sum = 0;
        if(root->left) {
            sum += root->left->data;
        }
        if(root->right) {
            sum += root->right->data;
        }
        if(sum != rootVal) {
            return false;
        }
        
        return isSum(root->left) && isSum(root->right);
    }
    bool isSumProperty(Node *root) {
        // code here

        return isSum(root);
    }
};