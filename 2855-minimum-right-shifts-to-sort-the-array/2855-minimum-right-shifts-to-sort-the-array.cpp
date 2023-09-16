class Solution {
public:
    bool sorted(vector<int>& nums){
        for(int i=1 ; i<nums.size() ; i++){
            if(nums[i] < nums[i-1])
                return false;
        }
        return true;
    }
    
    int minimumRightShifts(vector<int>& nums) {
        
        int n = nums.size();

        for(int i=0; i<n ; i++){
            if(sorted(nums))
                return i; //0
            for(int j=n-1 ; j>0 ; j--){
                swap(nums[j], nums[j-1]); 
                // Right shift the elements by swapping adjacent elements
            }
            
        }
           
        return -1; //if not equal to sorted
    }
};
