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

/*
1. we use bfs in this question to find sum of the levels 
2. While traversing take the sum of the child nodes & also keep storing the node in a buffer
3. After each stage of the BFS, traverse the buf & update the node with value sum - (child's sum)
*/
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val = 0;
    queue<TreeNode*> q;  q.push(root);
    while(!q.empty()){
        int n = q.size(), sum = 0;
        vector<TreeNode*> child_node;
        while(n--){
            TreeNode* node = q.front(); q.pop();
            child_node.push_back(node);
            if(node->left) { 
                q.push(node->left); 
                sum += node->left->val; 
            }
            if(node->right){ 
                q.push(node->right); 
                sum += node->right->val; 
            }
        }
        for(auto node: child_node){
            int  t = sum;
            if(node->left)  t -= node->left->val;
            if(node->right) t -= node->right->val;
            if(node->left)  node->left->val = t;
            if(node->right) node->right->val = t;
        }
    }
    return root;
    }
};