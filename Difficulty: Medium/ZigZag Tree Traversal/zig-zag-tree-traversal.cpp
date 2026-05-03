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
        queue<Node*> q;
        q.push(root);
        bool leftToRight = 1;
        
        while(!q.empty()) {
            int size = q.size();
            vector<int> arr;
            for(int i=0; i<size; i++) {
                Node* temp = q.front();
                q.pop();
                arr.push_back(temp->data);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            if(leftToRight) {
                for(int i=0; i<arr.size(); i++) {
                    ans.push_back(arr[i]);
                }
                leftToRight = !leftToRight;
            }
            else {
                for(int i=arr.size()-1; i>=0; i--) {
                    ans.push_back(arr[i]);
                }
                leftToRight = !leftToRight;
            }
        }
        
        return ans;
    }
};






