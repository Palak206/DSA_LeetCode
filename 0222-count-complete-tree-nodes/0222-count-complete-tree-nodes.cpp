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
// class Solution {
// public:
//     vector<int> v;
//     void inorder(TreeNode* root){
//         if(root == NULL)
//             return ;
        
//         inorder(root->left);
//         v.push_back(root->val);
//         inorder(root->right);
//     }
//     int countNodes(TreeNode* root) {
//         inorder(root);
        
//         return v.size();
//     }
// };

class Solution {
public:
    
    int dfs(TreeNode* root){
        if(root == NULL)
            return 0;
        
        return 1+dfs(root->left)+dfs(root->right);
        
    }
    int countNodes(TreeNode* root) {
        int ans = dfs(root);
        
        return ans;
    }
};