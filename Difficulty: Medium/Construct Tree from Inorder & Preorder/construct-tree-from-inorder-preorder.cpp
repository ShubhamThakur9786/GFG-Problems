/*
Definition for Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    Node* Solve(vector<int> &inorder, vector<int> &preorder, int si, int ei, int idx, unordered_map<int, int> mp) {
        if(si > ei) {
            return NULL;
        }
        Node* root = new Node(preorder[idx]);
        int pos = mp[preorder[idx]];
        //left
        root->left = Solve(inorder, preorder, si, pos-1, idx+1, mp);
        root->right = Solve(inorder, preorder, pos+1, ei, idx+(pos-si+1),mp);
        
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        unordered_map<int, int> mp;
        for(int i=0; i<inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        int startIndx = 0;
        int endIndx = preorder.size()-1;
        Node* ans = Solve(inorder, preorder, startIndx, endIndx, 0, mp);
        return ans;
    }
};



