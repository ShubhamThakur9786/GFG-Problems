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
    vector<int> rightView(Node *root) {
        //  code here
        queue<Node*> q;
        q.push(root);
        vector<int> ans;
        
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
            ans.push_back(arr[arr.size()-1]);
        }
        
        return ans;
    }
};