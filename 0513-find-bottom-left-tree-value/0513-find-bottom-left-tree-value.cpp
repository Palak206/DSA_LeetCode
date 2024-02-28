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
    
//     int findBottomLeftValue(TreeNode* root) {
//         queue<TreeNode*> q;
//         TreeNode* curr = root;
        
//         q.push(curr);
        
//         while(!q.empty()){
//             curr = q.front(); //pop till we reach to the last level
//             q.pop();
            
//             if(curr->right != NULL){
//                 q.push(curr->right);
//             }
            
//             if(curr->left != NULL){
//                 q.push(curr->left);
//             }
            
//         }
//         return curr->val;
//     }
// };

class Solution {
    int hmax = -1, ans = 0;
    void dfs(TreeNode* root, int level){
        if(!root) return;
        if(level>hmax) {
            hmax=level;
            ans=root->val;
        }
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root,0);
        return ans;
    }
};