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
    TreeNode *helper(vector<int> &preorder,int &idx,int n){
        if(idx==preorder.size() || preorder[idx]>n){
            return NULL;
        }
        TreeNode *root=new TreeNode(preorder[idx++]);
        root->left=helper(preorder,idx,root->val);
        root->right=helper(preorder,idx,n);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        return helper(preorder,idx,INT_MAX);
    }
};

// class Solution {
// public:
//     TreeNode* solve(vector<int>& preorder , int& idx, int size){
//         if(idx >= size)
//             return NULL;
        
//         TreeNode* root = new TreeNode(preorder[idx++]);
        
//         root->left = solve(preorder, idx, root->val);
//         root->right = solve(preorder, idx, size);
//         return root;
//     }
//     TreeNode* bstFromPreorder(vector<int>& preorder) {
//         int idx = 0;
//         return solve(preorder,0,preorder.size()-1);
//     }
// };