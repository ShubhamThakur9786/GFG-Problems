class Solution {
  public:
    
    string Solve(Node* root, unordered_map<string, int> &mp, vector<Node*> &temp) {
        if(!root) {
            return "N";
        } 
        
        string left = Solve(root->left, mp, temp);
        string right = Solve(root->right, mp, temp);
        
        string curr = to_string(root->data) + left + right;
        
        if(mp[curr] == 1) {
            temp.push_back(root);
        }
        mp[curr] += 1;
        return curr;
    }
    vector<Node*> printAllDups(Node* root) {
        // Code here
        vector<Node*> temp;
        if(!root) return temp;
        unordered_map<string, int> mp;
        
        Solve(root, mp, temp);
        return temp;
    }
};