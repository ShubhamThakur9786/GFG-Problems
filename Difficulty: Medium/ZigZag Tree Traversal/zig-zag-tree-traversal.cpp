/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
        vector<int> ans;
        if(!root) return ans;
        bool leftToRight = 1;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            
            for(int i=0; i<size; i++) {
                Node* temp = q.front();
                q.pop();
                level.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(!leftToRight) {
                reverse(level.begin(), level.end());
            }
            for(int val : level) {
                ans.push_back(val);
            }
            leftToRight = !leftToRight;
        }
        
        return ans;
    }
};








