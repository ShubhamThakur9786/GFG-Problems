/* Tree node structure 
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class NodeValue {
  public:
    int maxvalue, minvalue, size;
    NodeValue(int maxvalue, int minvalue, int size) {
        this->maxvalue = maxvalue;
        this->minvalue = minvalue;
        this->size = size;
    }
};

class Solution {
  public:
    NodeValue largBSTSize(Node* root) {
        if(!root) {
            return NodeValue(INT_MIN, INT_MAX, 0);
        }
        
        auto left = largBSTSize(root->left);
        auto right = largBSTSize(root->right);
        
        if((left.maxvalue < root->data && root->data < right.minvalue)) {
            //bst 
            return NodeValue(max(root->data, right.maxvalue), min(root->data, left.minvalue), 
                             1 + left.size + right.size);
        }
        
        return NodeValue(INT_MAX, INT_MIN, max(left.size, right.size));
    }
    int largestBst(Node *root) {
        // code here
        return largBSTSize(root).size;
    }
};