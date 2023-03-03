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
//     int sumRootToLeaf(TreeNode* root) {
//         solve(root,0);
//         return sum;
//     }
        
//     long sum=0;
//     void solve(TreeNode* &root,long val){
//         //base case
//         if(root==NULL){
//             return;
//         }
//         if(root->left==NULL && root->right==NULL){
//             sum+= (val*2 + root->val);
//             return;
//         }
//         solve(root->left,val*2+root->val);
//         solve(root->right,val*2+root->val);
//     }
    
    
// };


// class Solution {
// public:
//     int sumRootToLeaf(TreeNode* root) {
//         if(!root)
//             return 0;
//         solve(root,0);
//         return sum;
//     }
        
//     long sum=0;
//     void solve(TreeNode* &root,long val){
//         //base case
//         if(!root)
//             return;
        
//         val *= 10;
//         val += root->val;
//         if(!root->val && !root->right){
//             sum += val;
//             return;
//         }
//         solve(root->left, val);
//         solve(root->right, val);
//     }
    
    
// };

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        dfs(root,0);
        return ans;
    }
    long ans =0;
    void dfs(TreeNode *root,long val)
    {
        if(!root)
            return;
        // val *=10;
        val = val << 1; // left shift means val *=10;
        val += root->val;
        if(!root->left && !root->right)
        {
            ans+=val;
            return;
        }
       if(root->left) dfs(root->left,val);
       if(root->right) dfs(root->right,val);
    }

    
};