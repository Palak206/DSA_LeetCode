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
//if we do inorder traversal of BST hten we find element in sorted order


//1st approach use hashmap to count the freq of element
//if greater thn 1 then we stored in our ans
class Solution {
public:
    unordered_map<int,int>mp;
    
    //inorder trverasal
    void dfs(TreeNode* root){
        if(root == NULL)
            return;
        
        dfs(root->left);
        mp[root->val]++;
        dfs(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        dfs(root);
        vector<int>res;
        int maxFreq = 0;
        
        for(auto &m:mp){
            if(m.second > maxFreq){
                //means we get  new freq
                maxFreq = m.second;
                res= {};//again initiliaze bcoz new elem found
                //store in result
                res.push_back(m.first);
             }
            //if currfreq == maxfreq then push in the answer
            else if(m.second == maxFreq){
                res.push_back(m.first);
            }
        }
        return res;
    }
};