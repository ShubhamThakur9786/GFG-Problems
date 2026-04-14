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
    vector<vector<int>> verticalOrder(Node *root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        map<int, vector<int>> mp; //hd->nodes
        queue<pair<Node*, int>> q;
        
        q.push({root, 0});
        
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();
            
            int idx = temp.second;
            Node* node = temp.first;
            
            mp[idx].push_back(node->data);
            
            if(node->left) q.push({node->left, idx-1});
            if(node->right) q.push({node->right, idx+1});
        }
        
        //traverse map and put it in ans
        for(auto x : mp) {
            ans.push_back(x.second);
        }
        return ans;
    }
};
































