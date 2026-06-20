/* BST Node
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<Node*> &ans) {
        if(!root) {
            return;
        }
        
        inorder(root->left, ans);
        ans.push_back(root);
        inorder(root->right, ans);
    }
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        vector<Node*> ans;
        inorder(root, ans);
        
        vector<Node*> temp;
        temp.push_back(NULL);
        temp.push_back(NULL);
        
        for(int i=0; i<ans.size(); i++) {
            if(ans[i]->data < key) {
                temp[0] = ans[i];
            }
            if(ans[i]->data > key) {
                temp[1] = ans[i];
                break;
            }
        }
        return temp;
    }
};