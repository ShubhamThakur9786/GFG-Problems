/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
  public:
    void findLeft(Node* root, int pos, int &l) {
        if(!root) return;
        l = max(l, pos);
        
        findLeft(root->left, pos+1, l);
        findLeft(root->right, pos, l);
    }
    void findDiogonal(Node* root, int pos, vector<vector<int>> &temp) {
        if(!root) return;
        
        temp[pos].push_back(root->data);
        findDiogonal(root->left, pos+1, temp);
        findDiogonal(root->right, pos, temp);
    }
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if(!root) return ans;
        int l = 0;
        findLeft(root, 0, l);
        vector<vector<int>> temp(l+1);
        findDiogonal(root, 0, temp);
        
        for(int i=0; i<temp.size(); i++) {
            for(int j=0; j<temp[i].size(); j++) {
                ans.push_back(temp[i][j]);
            }
        }
        
        return ans;
    }
};















