
// T.c = O(2^N) = 2^3 = 8
// sort the array to compare the x's 2 = 2 ; 
// if we ignore the x=2 we will ignore all x
// if we take the x then we have 2 option either take it or ignore it
class Solution {
public:
    // vector<vector<int>> ans; using global var
    void solve(int i , vector<int>&nums ,vector<int>&temp , vector<vector<int>>& ans
              ,bool prev){
        
        if(i == nums.size()){
            ans.push_back(temp);
        }
        else{
            // to take the ith ele
            //if i ignore the previous val
            //to ignore the ith ele
            solve(i+1 , nums , temp , ans , false);//if element is not present
            if(i>0 && nums[i] == nums[i-1] && (!prev)){
                return;
            }
            temp.push_back(nums[i]);
            solve(i+1 , nums , temp, ans ,true );//if element is  present
            
            
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        solve(0, nums , temp, ans , false);
        return ans;
    }
};