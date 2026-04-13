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
    void findPos(Node* root, int pos, int &l, int &r) {
        if(!root) return;
        
        l = min(l, pos);
        r = max(r, pos);
        
        findPos(root->left, pos-1, l, r);
        findPos(root->right, pos+1, l, r);
    }
    vector<int> topView(Node *root) {
        // code here
        int l = 0;
        int r = 0;
        findPos(root,0,l,r);
        vector<int> ans(r-l+1);
        vector<int> vis(r-l+1, 0);
        if(!root) return ans;
        queue<Node*> q;
        queue<int> index;
        q.push(root);
        index.push(0-l);
        
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            int idx = index.front();
            index.pop();
            if(!vis[idx]) {
                ans[idx] = temp->data;
                vis[idx] = 1;
            }
            if(temp->left) {
                q.push(temp->left);
                index.push(idx-1);
            }
            if(temp->right) {
                q.push(temp->right);
                index.push(idx+1);
            }
        }
        return ans;
    }
};

















