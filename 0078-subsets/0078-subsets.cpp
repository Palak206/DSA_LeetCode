class Solution {
public:
    // vector<vector<int>> ans; using global var
    void solve(int i , vector<int>&nums ,vector<int>&temp , vector<vector<int>>& ans){
        if(i == nums.size()){
            ans.push_back(temp);
        }
        else{
            // to take the ith ele
            temp.push_back(nums[i]);
            solve(i+1 , nums , temp, ans);//if element is  present
            
            
            temp.pop_back();
            //to ignore the ith ele
            solve(i+1 , nums , temp , ans);//if element is not present
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums , temp, ans);
        return ans;
    }
};