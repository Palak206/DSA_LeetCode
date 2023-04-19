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
    int max_length = 0;
    void dfs(TreeNode* root , int dir ,int crnt_length ){
        if(!root) return;
        max_length = max(max_length , crnt_length);
        dfs(root->left,0,dir?crnt_length+1:1);
        dfs(root->right,1,dir?1:crnt_length+1);
    }

    int longestZigZag(TreeNode* root) {
        dfs(root,0,0); //top of the root tree
        dfs(root,1,0); 
        return max_length;
    }
        
    
};