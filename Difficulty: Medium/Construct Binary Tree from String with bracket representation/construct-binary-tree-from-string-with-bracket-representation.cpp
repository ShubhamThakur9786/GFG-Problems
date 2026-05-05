// User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/

class Solution {
  public:
    Node* buildTree(string &str, int &pos) {
        if (pos >= str.length()) return NULL;

        // Handle closing bracket
        if (str[pos] == ')') {
            pos++;
            return NULL;
        }

        // Parse number
        int data = 0;
        while (pos < str.length() && str[pos] != '(' && str[pos] != ')') {
            data = data * 10 + (str[pos] - '0');
            pos++;
        }

        Node* root = new Node(data);

        // Left subtree
        if (pos < str.length() && str[pos] == '(') {
            pos++;  // skip '('
            root->left = buildTree(str, pos);
        }

        // Right subtree
        if (pos < str.length() && str[pos] == '(') {
            pos++;  // skip '('
            root->right = buildTree(str, pos);
        }

        // Skip closing ')'
        if (pos < str.length() && str[pos] == ')') {
            pos++;
        }

        return root;
    }

    Node* treeFromString(string str) {
        int pos = 0;
        return buildTree(str, pos);
    }
};

// class Solution{
// public:
//     Node* buildTree(string str, int& index){
//         if(index >= str.length()) return NULL;
//         // if a closing bracket appears before a digit, that means its a null value and hence we handle it acoordingly
//         if(str[index] == ')'){
//             index++;
//             return NULL;
//         }
        
//         // Handling Multiple integers
//         int data = 0;
//         while(str[index] != '(' && str[index] != ')'){
//             data = data*10 + str[index]-'0';
//             index++;
//             if(index >= str.length()) break;
//         }
        
//         Node* root = new Node(data);
        
//         // if another opening bracket is there we either input left or right node
//         if(str[index] == '(') root->left = buildTree(str, ++index);
//         if(str[index] == '(') root->right = buildTree(str, ++index);
        
//         // if closing bracket appears we increase the index and move onto next element
//         if(str[index] == ')') index++;
//         return root;
//     }

    
//     Node *treeFromString(string str){
//         int index = 0;
//         return buildTree(str, index);
//     }
// };