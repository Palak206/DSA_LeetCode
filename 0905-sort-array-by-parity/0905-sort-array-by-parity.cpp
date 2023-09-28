class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();
        vector<int>res;
        
        for(int i=n-1; i>=0 ; i--){
            if(nums[i]%2 == 0)
                res.push_back(nums[i]);
        }
        for (int j : nums) {
            if (j % 2 != 0) {
                res.push_back(j);
            }
        }
        return res;
    }
};