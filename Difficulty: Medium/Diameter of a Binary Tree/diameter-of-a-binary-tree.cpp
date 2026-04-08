/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int diameterRed(Node* root, int &maxi) {
        if(root == NULL) {
            return 0;
        }
        
        int lheight = diameterRed(root->left, maxi);
        int rheight = diameterRed(root->right, maxi);
        
        if(lheight+rheight > maxi) 
            maxi = lheight+rheight;
            
        return 1 + max(lheight, rheight);
    }
    int diameter(Node* root) {
        // code here
        int maxi = 0;
        diameterRed(root, maxi);
        return maxi;
    }
};