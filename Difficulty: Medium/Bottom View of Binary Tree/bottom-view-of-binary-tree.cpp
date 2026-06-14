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
    vector<int> bottomView(Node *root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        
        queue<pair<Node*, int>> q; //node, level
        q.push({root, 0});
        map<int, int> mp; //level, nodevalue
        
        while(!q.empty()) {
            auto temp = q.front();
            Node* node = temp.first;
            int level = temp.second;
            q.pop();
            
            mp[level] = node->data;
            
            if(node->left) q.push({node->left, level-1});
            if(node->right) q.push({node->right, level+1});
        }
        
        for(auto i : mp) {
            ans.push_back(i.second);
        }
        return ans;
    }
};