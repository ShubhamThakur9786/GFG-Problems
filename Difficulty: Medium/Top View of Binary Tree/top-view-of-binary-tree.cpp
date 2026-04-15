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
    // void findPos(Node* root, int pos, int &l, int &r) {
    //     if(!root) return;
        
    //     l = min(l, pos);
    //     r = max(r, pos);
        
    //     findPos(root->left, pos-1, l, r);
    //     findPos(root->right, pos+1, l, r);
    // }
    // vector<int> topView(Node *root) {
    //     // code here
    //     int l = 0;
    //     int r = 0;
    //     findPos(root,0,l,r);
    //     vector<int> ans(r-l+1);
    //     vector<int> vis(r-l+1, 0);
    //     if(!root) return ans;
    //     queue<Node*> q;
    //     queue<int> index;
    //     q.push(root);
    //     index.push(0-l);
        
    //     while(!q.empty()) {
    //         Node* temp = q.front();
    //         q.pop();
    //         int idx = index.front();
    //         index.pop();
    //         if(!vis[idx]) {
    //             ans[idx] = temp->data;
    //             vis[idx] = 1;
    //         }
    //         if(temp->left) {
    //             q.push(temp->left);
    //             index.push(idx-1);
    //         }
    //         if(temp->right) {
    //             q.push(temp->right);
    //             index.push(idx+1);
    //         }
    //     }
    //     return ans;
    // }
    
    vector<int> topView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            Node* node = temp.first;
            int idx = temp.second;
            
            if(mp.find(idx) == mp.end()) {
                //not found
                mp[idx] = node->data;
            }
            
            if(node->left) q.push({node->left, idx-1});
            if(node->right) q.push({node->right, idx+1});
        }
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

















