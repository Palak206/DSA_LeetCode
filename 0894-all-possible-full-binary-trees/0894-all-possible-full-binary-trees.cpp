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
// full bt only possible for odd number 1 3 5 7 9.....
class Solution {
public:
    vector<vector<TreeNode*>>dp;
    // using dp bcoz we save the tree for nodes number 
    // supoose 5 then it's repeated that's why
    
    vector<TreeNode*> solve(int n) {
        //for even number full bt not possible 2 4 6..
        if(n%2 == 0)
            return {};
        if(dp[n].size() != 0)
            return dp[n];
        
        if(n == 1){
            TreeNode* new_node = new TreeNode(0);
            return {new_node};
        }
        
        vector<TreeNode*> res;
        
        for(int i=1 ; i<n ; i++){
            vector<TreeNode*>left = solve(i);
            vector<TreeNode*>right  = solve(n-i-1);
            
            for(TreeNode*l : left){
                for(TreeNode*r : right){
                    TreeNode* root = new TreeNode(0) ;
                    
                    root->left = l;
                    root->right = r;
                    
                    res.push_back(root);
                }
            }
        }
        return dp[n] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        dp.resize(n+1);
        return solve(n);
    }
};