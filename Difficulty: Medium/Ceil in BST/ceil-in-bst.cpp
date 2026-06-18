/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int findCeil(Node* root, int x) {
        // code here
        int ans = -1;
        while(root != NULL) {
            if(root->data == x) {
                ans = root->data;
                return ans;
            }
            else if(root->data < x) {
                root = root->right;
            }
            else {
                ans = root->data;
                root = root->left;
            }
        }
        return ans;
    }
};
