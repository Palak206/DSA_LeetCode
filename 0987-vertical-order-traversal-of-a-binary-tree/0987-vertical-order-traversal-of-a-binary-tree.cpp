// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int , map<int , multiset<int>>> nodes;
        queue<pair<TreeNode* , pair<int , int>>> todo;
   //            ( node    ,    vertical, level order)
        
        todo.push({root , {0 , 0}}); // initially ( 3 , 0 ,0)
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first; //node
            int x = p.second.first; // for vertical(-1(left) , +1(right))
            int y = p.second.second;  // for  level(+1)

            
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left,{x-1 , y+1}});
            }
            
            if(node->right){
                todo.push({node->right,{x+1 , y+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto p:nodes){
            vector<int>col;
            for(auto q:p.second){
                //p.second = map<int(level)  multiset>
                col.insert(col.end() , q.second.begin() , q.second.end());
            }
        
           ans.push_back(col);
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) 
//     {
//         map<int, map<int, multiset<int>>> nodes;
//         queue<pair<TreeNode*, pair<int, int>>> todo;
//         todo.push({root, {0, 0}});
//         while(!todo.empty())
//         {
//             auto p = todo.front();
//             todo.pop();         
//             TreeNode* node=p.first;     // take the node
//             int x = p.second.first;        // take the vertical order
//             int y = p.second.second;    // take the level

//             nodes[x][y].insert(node->val);      // insert that into your DS, multiset

//             if(node->left)        // after that you insert it into the queue, vertical-1, lvl+1
//             {
//                 todo.push({node->left, {x-1, y+1}});
//             }
//             if(node->right)     // if there is a right, insert into
//             {
//                 todo.push({node->right, {x+1, y+1}});       // vertical+1, level+1
//             }
//         }
//         vector<vector<int>> ans;

//         for(auto p : nodes)     // traverse through the map
//         {
//             vector<int> col;
//             // p.second -> map<int, multiset<int>>
//             for(auto q : p.second)
//             {
//                 // for every element you are inserting right, at the end
//                 // the entire multiset
//                 // lets say for a vertical 0, we had the levels 0, 1 and 2
//                 // so first we traversed for 0, got a multiset, inserted it into the map
//                 // then we traversed for 1, got a multiset, inserted it into the the map
//                 // then for 2, got another multiset, inserted it inot the map 
//                 col.insert(col.end(), q.second.begin(), q.second.end());
//             }
//             // once we get the entire vertical, we insert it into the ans
//             ans.push_back(col);
//         }
            
        
//         return ans;
//     }
// };