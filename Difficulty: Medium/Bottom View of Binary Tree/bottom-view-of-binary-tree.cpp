/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
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
            
            mp[idx] = node->data;
            
            if(node->left) q.push({node->left, idx-1});
            if(node->right) q.push({node->right, idx+1});
        }
        
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};
















