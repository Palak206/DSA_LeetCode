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
    vector<int>ans;
    //inorder will sort the array 
    void inorder(TreeNode *root){
        if(root == NULL) return;
        
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        for(int i=0; i<ans.size(); i++){
            for(int j=i+1; j<ans.size(); j++){
                if(ans[i] + ans[j] == k)
                    return true;
                
            }
        }
        return false;
    }
};