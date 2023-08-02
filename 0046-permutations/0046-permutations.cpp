
// class Solution {
// public:
//     vector<vector<int>> ans;
//     void perm(vector<int>& nums , int i ){// pass reference it'll create copy of no.
//         if(i == nums.size()){
//             ans.push_back(nums);
//             return ;
//         }
//         for(int j= i; j<nums.size();j++){
//             swap(nums[i],nums[j]); //1,2( 2,1)
//             perm(nums , i+1);
//             swap(nums[i] ,nums[j]);//undo the chage
//         }
//     }
//     vector<vector<int>> permute(vector<int>& nums) {
      
//         perm(nums , 0);
//         return ans;
//     }
// };


class Solution {
public:
    // int n;
    vector<vector<int>> res;
    unordered_set<int>st;//s.c = o(1)
    
    void solve(vector<int>&nums , vector<int>&temp){
        if(temp.size() == nums.size()){
             res.push_back(temp);
             return;
        }
        for(int i=0 ; i<nums.size(); i++){
            if(st.find(nums[i]) == st.end()){
                temp.push_back(nums[i]);
                st.insert(nums[i]);
                
                solve(nums , temp);//if element is  present
                
                temp.pop_back();//to ignore the ith ele
                st.erase(nums[i]);
                // solve(nums , temp );//if element is not present
            }
            
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums){
        // vector<vector<int>> res;
        vector<int>temp;
        
        
        solve(nums , temp );
        return res;
    }
};
