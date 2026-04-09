// User function Template for C++

class Solution {
  public:
    vector<int> largestValues(Node* root) {
        // code here
        vector<int> ans;
        
        queue<Node*> q;
        q.push(root);
        Node* temp;
        
        while(!q.empty()) {
            int size = q.size();
            int maxi = -1;
            for(int i=0; i<size; i++) {
                temp = q.front();
                q.pop();
                maxi = max(maxi, temp->data);
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(maxi);
        }
        
        return ans;
    }
};