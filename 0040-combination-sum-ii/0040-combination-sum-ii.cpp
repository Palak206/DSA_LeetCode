
class Solution {
public:
    void solve(int i , vector<int>&candidates , int target ,vector<int>&temp , vector<vector<int>>& ans , bool prev){
//         if(sum == target){
//             ans.push_back(temp);
//             return;
//         }
        
//         if(sum > target)
//             return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        
        if(target < 0){
            return;
        }
        
        if(i == candidates.size()){
            return;
        }
        
        else{
            // to take the ith ele
            //if i ignore the previous val
            //to ignore the ith ele
            solve(i+1 , candidates ,target, temp , ans , false);//if element is not present
            if(i>0 && candidates[i] == candidates[i-1] && (!prev)){
                return;
            }
            
            temp.push_back(candidates[i]);
            solve(i+1 , candidates ,target - candidates[i] , temp, ans ,true );
            //if element is  present
            
            
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin() , candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, candidates ,target , temp, ans , false);
        return ans;
    }
};