class Solution {
public:
    int findMaxK(vector<int>& nums) {        
        int maxi = -1;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] == (-nums[j])){
                    maxi = max(maxi , abs(nums[i]));
                }
            }
        }
        return maxi;
    }
};