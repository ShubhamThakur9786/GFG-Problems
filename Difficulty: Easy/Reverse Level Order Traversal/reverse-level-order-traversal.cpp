/*
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
    vector<int> reverseLevelOrder(Node *root) {
        // code here
        vector<int> ans;
        stack<int> st;
        if(root == NULL) return ans;
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()) {
            Node* temp = q.front();
            q.pop();
            
            st.push(temp->data);
            
            if(temp->right) q.push(temp->right);
            if(temp->left) q.push(temp->left);
        }
        
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};