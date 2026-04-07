/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    int height(Node* root) {
        // code here
        // if(root == NULL) return 0;
        // queue<Node*> q;
        // q.push(root);
        // int height = 0;
        
        // while(!q.empty()) {
        //     int size = q.size();
        //     height++;
            
        //     for(int i=0; i<size; i++) {
        //         Node* temp = q.front();
        //         q.pop();
                
        //         if(temp->left) q.push(temp->left);
        //         if(temp->right) q.push(temp->right);
        //     }
            
        // }
        // return height;
        
        // code here
        if(root == NULL) {
            return -1;
        }
        
        return 1 + max(height(root->left), height(root->right));
    }
};