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
//T.C & S.C = O(N)
class Solution {
public:
    
    vector<int>res;
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
        
        int maxFreq = 0;
        
        //find the maxfreq in the map
        for(auto &m:mp){
            maxFreq = max(maxFreq , m.second);
        }
        
        //if the freq == maxfreq ; 2 = 2
        for(auto &m:mp){
            if( m.second == maxFreq ){
                res.push_back(m.first);
            }
        }
        
        return res;
    }
};


// class Solution {
// public:
//     unordered_map<int,int>mp;
    
//     //inorder trverasal
//     void dfs(TreeNode* root){
//         if(root == NULL)
//             return;
        
//         dfs(root->left);
//         mp[root->val]++;
//         dfs(root->right);
//     }
    
//     vector<int> findMode(TreeNode* root) {
//         dfs(root);
//         vector<int>res;
//         int maxFreq = 0;
        
//         for(auto &m:mp){
//             if(m.second > maxFreq){
//                 //means we get  new freq
//                 maxFreq = m.second;
//                 res= {};//again initiliaze bcoz new elem found
//                 //store in result
//                 res.push_back(m.first);
//              }
//             //if currfreq == maxfreq then push in the answer
//             else if(m.second == maxFreq){
//                 res.push_back(m.first);
//             }
//         }
//         return res;
//     }
// };


// class Solution {
// public:
//     int currNum = 0;
//     int currFreq = 0;
//     int maxFreq = 0;
//     vector<int>ans;
    
//     //inorder trverasal
//     void dfs(TreeNode* root){
//         if(root == NULL)
//             return;
        
//         dfs(root->left);
        
//         if(root->val == currNum){
//             currFreq++;
//         }
//         else{
//             currNum = root->val;
//             currFreq = 1;
//             //bcoz we got new ele
//         }
        
//         //if currfreq > mxfreq then update the maxfreq in the ans
//         if(currFreq > maxFreq){
//             ans = {};
//             maxFreq = currFreq;
//         }
        
//         if(currFreq == maxFreq){
//             ans.push_back(root->val);
//         }
        
//         dfs(root->right);
//     }
    
//     vector<int> findMode(TreeNode* root) {
//         dfs(root);
        
//         return ans;
//     }
// };