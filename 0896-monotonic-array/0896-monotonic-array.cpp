// Monotone increasing: nums[i] <= nums[j] for all i <= j.
// Monotone decreasing: nums[i] >= nums[j] for all i <= j.

class Solution {
public:
    
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool decArr = true; // if it's decreasing
        bool incArr = true;
        
        for(int i=1; i<n ;i++){
            if( nums[i] > nums[i-1]){
                decArr =  false;
            }
            else if(nums[i] < nums[i-1]){
                incArr = false;
            }
            if (!incArr && !decArr) {
                return false;
            }
                
      }
        
        return true;
    }
};
