class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i , vector<int>&nums ,vector<int>&temp){
        if(i == nums.size()){
            ans.push_back(temp);
        }
        else{
            // to take the ith ele
            temp.push_back(nums[i]);
            solve(i+1 , nums , temp);//if element is  present
            
            
            temp.pop_back();
            //to ignore the ith ele
            solve(i+1 , nums , temp);//if element is not present
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        solve(0, nums , temp);
        return ans;
    }
};