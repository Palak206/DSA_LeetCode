/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(root == NULL) return {};
        vector<int>res;
        
        //bfs
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int max_val = INT_MIN; //push the max val in our result
            
            for(int i=0 ; i<size ; i++){
                TreeNode* node = q.front();
                q.pop();
                
                max_val = max(max_val , node->val);
                
                if(node->left != NULL) q.push(node->left);
                 if(node->right != NULL) q.push(node->right);
            }   
                res.push_back(max_val);
            
        }
        return res;
    }
};
