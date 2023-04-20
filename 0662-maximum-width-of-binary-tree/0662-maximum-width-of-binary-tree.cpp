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
// width = no. od node between any two node
//               1      index = 0
//            /    \
//           3      2    i = 1
//          / \       \
//          5  3       9   i = 2
//         1  1   1   1 = 4
         // (5 , 3 null ,9)


 //             1
//            /    \
//           3      2
//          / \    /  \
//         5   n   n   9
//       / \  / \  /\   / \
//      6  n  n  n n n 7   n = 8

// T.C & S.C = O(N)
class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int ans = 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root , 0});  // {1,0(index = 0)}
        while(!q.empty()){
            int size = q.size();
            int min = q.front().second;
            int first = 0 ,last = 0;
            
            for(int i = 0 ; i<size ; i++){
                // when we do a tree traversal and input is given as an array so we acces left & right node using (2*i+1 = left),(2*i+2 = right)
                int curr_node = q.front().second - min;  //  (2*0+1) = 1, 1-1=0 ,
                // 
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0)
                    first = curr_node; // 1
                if(i == size-1)
                    last = curr_node;
                
                if(node->left != NULL)
                    q.push({node->left , (long long)2*curr_node+1});  //{3  2*0+1}
                if(node->right)
                    q.push({node->right , (long long)2*curr_node+2});  //{2 , 2*0+2}
                
                
            }
//             width = last-first+1
            ans = max(ans ,last-first+1);

        }
        
        return ans;
    }
};