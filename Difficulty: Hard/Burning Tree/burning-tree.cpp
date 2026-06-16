/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void parent(Node* root, map<Node*, Node*> &mp, int targ, Node* &newTarg) {
        if(!root) return;
        if(root->data == targ) {
            newTarg = root;
        }
        if(root->left) mp[root->left] = root;
        if(root->right) mp[root->right] = root;
        
        parent(root->left, mp, targ, newTarg);
        parent(root->right, mp, targ, newTarg);
    }

    int minTime(Node* root, int target) {
        // code here
        map<Node*, Node*> mp;
        Node* newTarg = NULL;
        parent(root, mp, target, newTarg);
        
        queue<Node*> q;
        unordered_map<Node*, bool> vis;
        q.push(newTarg);
        vis[newTarg] = true;
        int time = 0;
        
        while(!q.empty()) {
            int t = 0;
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                Node* temp = q.front();
                q.pop();
                if(temp->left && !vis[temp->left]) {
                    t = 1;
                    q.push(temp->left);
                    vis[temp->left] = true;
                }
                if(temp->right && !vis[temp->right]) {
                    t = 1;
                    q.push(temp->right);
                    vis[temp->right] = true;
                }
                if(mp[temp] && !vis[mp[temp]]) {
                    t = 1;
                    q.push(mp[temp]);
                    vis[mp[temp]] = true;
                }
            }
            
            if(t) {
                time++;
            }
        }
        
        return time;
    }
};




















