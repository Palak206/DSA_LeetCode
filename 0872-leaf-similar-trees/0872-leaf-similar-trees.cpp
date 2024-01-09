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
//create 2 vector and push the leaf node in vec
//if vec1 == vec2  return true ,return false
// void inorder(TreeNode* root, vector<int> &v)
//     {
//         if(root!=NULL)
//         {
//             inorder(root->left, v);
//             if(root->left == NULL && root->right == NULL)
//             {
//                 v.push_back(root->val);
//             }
//             inorder(root->right,v);
//         }
//     }
//     bool leafSimilar(TreeNode* root1, TreeNode* root2) 
//     {
//         vector<int> v,v1;
//         inorder(root1,v);
//         inorder(root2,v1);
//         return v==v1;
//     }
// };
class Solution {
public:
    void inorder(TreeNode* root, vector<int>&v){
        if(root == NULL)
            return;
        
           inorder(root->left,v);
        
           if(root->left == NULL && root->right == NULL)
               v.push_back(root->val); //push the leaf node
        
           inorder(root->right,v);
        
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>v1, v2;
        
        inorder(root1,v1);
        inorder(root2,v2);
        
        if(v1 == v2)
            return true;
        return false;
    }
};