class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n= nums.size();
        vector<int>res;
        //we can run loop from 0 to n-1 also
        for(int i=n-1; i>=0 ; i--){
            if(nums[i]%2 == 0)
                res.push_back(nums[i]);
        }
        for (int j = 0; j<n; j++) {
            if (nums[j] % 2 != 0) {
                res.push_back(nums[j]);
            }
        }
        return res;
    }
};