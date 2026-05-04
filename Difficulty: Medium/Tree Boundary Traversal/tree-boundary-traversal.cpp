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
    
    void left(Node* root, vector<int> &ans) {
        if(!root) return;
        if(!root->left && !root->right) return; 
        ans.push_back(root->data);
        
        if(root->left) {
            left(root->left, ans);
        }
        else {
            left(root->right, ans);
        }
    }
    
    void leaf(Node* root, vector<int> &ans) {
        if(!root) return;
        if(!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }
        leaf(root->left, ans);
        leaf(root->right, ans);
    }
    
    void right(Node* root, vector<int> &ans) {
        if(!root) return;
        if(!root->left && !root->right) return;
        
        
        if(root->right) {
            right(root->right, ans);
        }
        else {
            right(root->left, ans);
        }
        
        ans.push_back(root->data);
    }
    
    
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int> ans;
        
        if(!root) return ans;
        ans.push_back(root->data);
        
        left(root->left, ans);
        if(root->left || root->right)
            leaf(root, ans);
        right(root->right, ans);
        
        
        return ans;
    }
};











