/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// class Solution {
// public:
//     Node* connect(Node* root) {
//         if(root == NULL) return NULL;
//         queue<Node*> q;
//         Node* curr = root;
//         q.push(curr);
        
//         while(!q.empty()){
//             int n = q.size();
//             vector<Node*> v;
            
//             for(int i=0; i<n; i++){
//                 curr = q.front();
//                 q.pop();
                
//                 v.push_back(curr);
                
//                 if(curr->left)
//                     q.push(curr->left);
//                 if(curr->right)
//                     q.push(curr->right);
            
//             }
//             int j=0 ;
//             for(j=0; j<v.size()-1; j++){
//                 v[j]->next = v[j+1];
//             }
//             v[j] = NULL;
            
            
//         }
//         return root;
//     }
// };

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return NULL;
        queue<Node*> q;
        Node* curr = root;
        q.push(curr);
        
        while(!q.empty()){
            int n = q.size();
            
            while(n--){
                curr = q.front();
                q.pop();
                
                if(n == 0)
                    curr->next = NULL;
                else
                    curr->next = q.front();
                
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            
            }
        }
        return root;
    }
};

